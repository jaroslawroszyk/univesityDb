#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "mocks/FileHandlerMock.hpp"
#include "FileHandler.hpp"
#include "Database.hpp"
#include "Student.hpp"
#include <fstream>

using namespace testing;

namespace
{
    const std::string FILENAME = "test_file.csv";
    const int sizeOfDb = 2;
} // namespace

class FileHandlerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        testFileName = FILENAME;
        fileHandlerMock = std::make_unique<NiceMock<FileHandlerMock>>(testFileName, Mode::Write);
        db = std::make_unique<Database>();

        db->add(Student("John", "Doe", "123 Main St", 12345, "1234567890", Gender::Male));
        db->add(Student("Jane", "Smith", "456 Elm St", 54321, "0987654321", Gender::Female));
    }

    void TearDown() override
    {
        std::remove(testFileName.c_str());
    }

    std::unique_ptr<NiceMock<FileHandlerMock>> fileHandlerMock;
    std::unique_ptr<Database> db;
    std::string testFileName;
};

TEST_F(FileHandlerTest, WriteToCsvFile)
{
    EXPECT_CALL(*fileHandlerMock, writeToCsvFile(testing::_))
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

    fileHandlerMock->writeToCsvFile(*db);

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
    NiceMock<FileHandlerMock> fileHandlerMock(testFileName, Mode::Read);

    EXPECT_CALL(fileHandlerMock, writeToCsvFile(testing::_))
        .WillOnce(testing::Throw(std::runtime_error("Cannot write to the file.Invalid file mode.")));

    EXPECT_THROW(fileHandlerMock.writeToCsvFile(*db), std::runtime_error);
}

TEST_F(FileHandlerTest, ReadDbFromFile)
{
    fileHandlerMock->readDbFromFile(*db);
    db->show();
    ASSERT_EQ(db->getSize(), 2);
    ASSERT_TRUE(db->searchByIndex(12345));
    ASSERT_TRUE(db->searchByName("Jane"));
    ASSERT_FALSE(db->searchByGender(Gender::Other));
    ASSERT_TRUE(db->searchByGender(Gender::Female));
}

TEST_F(FileHandlerTest, ReadDbFromFile_InvalidFileMode)
{
    NiceMock<FileHandlerMock> fileHandlerMock(testFileName, Mode::Write);

    EXPECT_CALL(fileHandlerMock, readDbFromFile(testing::_))
        .WillOnce(testing::Throw(std::runtime_error("Cannot read from the file. Invalid file mode.")));

    EXPECT_THROW(fileHandlerMock.readDbFromFile(*db), std::runtime_error);

}
