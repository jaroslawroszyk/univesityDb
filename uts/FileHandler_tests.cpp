#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include "Database.hpp"
#include "FileHandler.hpp"
#include "Student.hpp"

using namespace testing;

namespace
{
    const std::string FILENAME = "test_file.csv";
    const int sizeOfDb = 2;
} // namespace

class MockFileHandler : public FileHandler
{
public:
    MockFileHandler(const std::string& filename, Mode mode) : FileHandler(filename, mode) {}

    MOCK_METHOD(void, writeToCsvFile, (const Database& db), ());
    MOCK_METHOD(void, readDbFromFile, (Database& db), ());
};


class FileHandlerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        testFileName = FILENAME;
        mockFileHandler = std::make_unique<MockFileHandler>(testFileName, Mode::Write);
        db = std::make_unique<Database>();

        db->add(Student("John", "Doe", "123 Main St", 12345, "1234567890", Gender::Male));
        db->add(Student("Jane", "Smith", "456 Elm St", 54321, "0987654321", Gender::Female));
    }

    void TearDown() override
    {
        std::remove(testFileName.c_str());
    }

    std::unique_ptr<MockFileHandler> mockFileHandler;
    std::unique_ptr<Database> db;
    std::string testFileName;
};

TEST_F(FileHandlerTest, WriteToCsvFile)
{
    EXPECT_CALL(*mockFileHandler, writeToCsvFile(testing::_))
        .WillOnce(testing::Invoke([&](const Database& db)
            {
                std::ofstream fileStream(testFileName);
                fileStream << "Name, Surname, Address, Pesel, Gender\n";
                for (const auto& student : db.getStudents())
                {
                    fileStream << student.getName() << ", "
                        << student.getSurname() << ", "
                        << student.getAddress() << ", "
                        << student.getPesel() << ", "
                        << GenderToString(student.getGender()) << "\n";
                }
                fileStream.flush();
                fileStream.close();
            }));

    mockFileHandler->writeToCsvFile(*db);

    std::ifstream fileStream(testFileName);
    EXPECT_TRUE(fileStream.is_open());

    std::string line{};
    std::getline(fileStream, line); // skip HEADER Name, Surname, Address, Pesel, Gender 

    std::getline(fileStream, line);
    EXPECT_EQ(line, "John, Doe, 123 Main St, 1234567890, Male");

    std::getline(fileStream, line);
    EXPECT_EQ(line, "Jane, Smith, 456 Elm St, 0987654321, Female");

    fileStream.close();
}

TEST_F(FileHandlerTest, WriteToCsvFile_InvalidFileMode)
{
    EXPECT_CALL(*mockFileHandler, writeToCsvFile(testing::_))
        .WillOnce(testing::Invoke([&](const Database& /*db*/)
            {
                throw std::runtime_error("Invalid file mode");
            }));

    EXPECT_THROW(mockFileHandler->writeToCsvFile(*db), std::runtime_error);
}

TEST_F(FileHandlerTest, ReadDbFromFile)
{
    EXPECT_CALL(*mockFileHandler, readDbFromFile(testing::_))
        .WillOnce(testing::Invoke([&](Database& db)
            {
                std::ifstream fileStream(testFileName);
                std::string line{};
                std::getline(fileStream, line); // skip HEADER Name, Surname, Address, Pesel, Gender 

                while (std::getline(fileStream, line))
                {
                    std::istringstream iss(line);
                    std::string name, surname, address, pesel, genderStr;
                    std::getline(iss, name, ',');
                    std::getline(iss, surname, ',');
                    std::getline(iss, address, ',');
                    std::getline(iss, pesel, ',');
                    std::getline(iss, genderStr, ',');

                    Gender gender = StringToGender(genderStr);
                    db.add(Student(name, surname, address, 0, pesel, gender));
                }

                fileStream.close();
            }));

    mockFileHandler->readDbFromFile(*db);

    ASSERT_EQ(db->getSize(), sizeOfDb);
    ASSERT_TRUE(db->searchByIndex(12345));
    ASSERT_TRUE(db->searchByName("Jane"));
    ASSERT_FALSE(db->searchByGender(Gender::Other));
    ASSERT_TRUE(db->searchByGender(Gender::Female));
}

TEST_F(FileHandlerTest, ReadDbFromFile_InvalidFileMode)
{
    EXPECT_CALL(*mockFileHandler, readDbFromFile(testing::_))
        .WillOnce(testing::Invoke([&](Database& /*db*/)
            {
                throw std::runtime_error("Invalid file mode");
            }));

    EXPECT_THROW(mockFileHandler->readDbFromFile(*db), std::runtime_error);
}