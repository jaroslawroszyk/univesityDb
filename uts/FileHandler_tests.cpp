#include <gtest/gtest.h>
#include <fstream>
#include "Database.hpp"
#include "FileHandler.hpp"
#include "Student.hpp"

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
        fileHandler = std::make_unique<FileHandler>(testFileName, Mode::Write);
        db = std::make_unique<Database>();

        db->add(Student("John", "Doe", "123 Main St", 12345, "1234567890", Gender::Male));
        db->add(Student("Jane", "Smith", "456 Elm St", 54321, "0987654321", Gender::Female));
    }

    void TearDown() override
    {
        std::remove(testFileName.c_str());
    }

    std::unique_ptr<FileHandler> fileHandler;
    std::unique_ptr<Database> db;
    std::string testFileName;
};

TEST_F(FileHandlerTest, WriteToCsvFile)
{
    fileHandler->writeToCsvFile(*db);

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
    fileHandler = std::make_unique<FileHandler>(testFileName, Mode::Read);
    EXPECT_THROW(fileHandler->writeToCsvFile(*db), std::runtime_error);
}

TEST_F(FileHandlerTest, ReadDbFromFile)
{
    fileHandler = std::make_unique<FileHandler>(testFileName, Mode::Read);
    fileHandler->readDbFromFile(*db);

    ASSERT_EQ(db->getSize(), sizeOfDb);
    ASSERT_TRUE(db->searchByIndex(12345));
    ASSERT_TRUE(db->searchByName("Jane"));
    ASSERT_FALSE(db->searchByGender(Gender::Other));
    ASSERT_TRUE(db->searchByGender(Gender::Female));
}

TEST_F(FileHandlerTest, ReadDbFromFile_InvalidFileMode)
{
    fileHandler = std::make_unique<FileHandler>(testFileName, Mode::Write);
    EXPECT_THROW(fileHandler->readDbFromFile(*db), std::runtime_error);
}
