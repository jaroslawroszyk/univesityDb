#include <gtest/gtest.h>
#include "Database.hpp"
#include "Student.hpp"
#include "Gender.hpp"

namespace
{
    const int firstStudentIndex = 12345;
    const int secondStudentIndex = 54321;
    const std::string firstStudentPesel{ "1234567890" };
    const std::string secondStudentPesel{ "0987654321" };
} // namespace

class DatabaseTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        db.add(Student("John", "Doe", "123 Main St", firstStudentIndex, firstStudentPesel, Gender::Male));
        db.add(Student("Jane", "Smith", "456 Elm St", secondStudentIndex, secondStudentPesel, Gender::Female));
    }

    Database db;
};

TEST_F(DatabaseTest, SearchByName_ExistingName)
{
    EXPECT_TRUE(db.searchByName("John"));
}

TEST_F(DatabaseTest, SearchByName_NonExistingName)
{
    EXPECT_FALSE(db.searchByName("Janeta"));
}

TEST_F(DatabaseTest, SearchBySurname_ExistingSurname)
{
    EXPECT_TRUE(db.searchBySurname("Doe"));
}

TEST_F(DatabaseTest, SearchBySurname_NonExistingSurname)
{
    EXPECT_FALSE(db.searchBySurname("Smiths"));
}

TEST_F(DatabaseTest, SearchByIndex_ExistingIndex)
{
    EXPECT_TRUE(db.searchByIndex(firstStudentIndex));
}

TEST_F(DatabaseTest, SearchByIndex_NonExistingIndex)
{
    const int nonExistingIdx = 12;
    EXPECT_FALSE(db.searchByIndex(nonExistingIdx));
}

TEST_F(DatabaseTest, SearchByPesel_ExistingPesel)
{
    EXPECT_TRUE(db.searchByPesel(firstStudentPesel));
}

TEST_F(DatabaseTest, DeleteByPesel_NonExistingPesel)
{
    const std::string nonExistingPesel{ "12345678910" };
    EXPECT_FALSE(db.deleteByPesel(nonExistingPesel));
}

TEST_F(DatabaseTest, SearchByGender_ExistingGender)
{
    EXPECT_TRUE(db.searchByGender(Gender::Male));
}

TEST_F(DatabaseTest, DeleteBySurname_ExistingSurname)
{
    EXPECT_TRUE(db.deleteBySurname("Doe"));
    EXPECT_FALSE(db.searchBySurname("Doe"));
}

TEST_F(DatabaseTest, DeleteBySurname_NonExistingSurname)
{
    EXPECT_FALSE(db.deleteBySurname("Smiths"));
}

TEST_F(DatabaseTest, DeleteByIndex_ExistingIndex)
{
    EXPECT_TRUE(db.deleteByIndex(firstStudentIndex));
    EXPECT_FALSE(db.deleteByIndex(firstStudentIndex));
}

TEST_F(DatabaseTest, DeleteByIndex_NonExistingIndex)
{
    const int nonExistingIdx = 1233245;
    EXPECT_FALSE(db.deleteByIndex(nonExistingIdx));
}

TEST_F(DatabaseTest, DeleteByPesel_ExistingPesel)
{
    EXPECT_TRUE(db.deleteByPesel(firstStudentPesel));
    EXPECT_FALSE(db.searchByPesel(firstStudentPesel));
}

TEST_F(DatabaseTest, GetSize_AfterAddingTwoStudentIntoNewDatabase)
{
    Database newDb{};
    newDb.add(Student("David", "Jones", "12 Main St", 001, firstStudentPesel, Gender::Male));
    newDb.add(Student("Emily", "Williams", "46 Elm St", 002, secondStudentPesel, Gender::Female));
    int expectedSize = 2;
    EXPECT_EQ(newDb.getSize(), expectedSize);
}
