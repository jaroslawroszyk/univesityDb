#include <gtest/gtest.h>
#include "Database.hpp"
#include "Student.hpp"
#include "Gender.hpp"

class DatabaseTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Inicjalizacja bazy danych
        db.add(Student("John", "Doe", "123 Main St", 12345, "1234567890", Gender::Male));
        db.add(Student("Jane", "Smith", "456 Elm St", 54321, "0987654321", Gender::Female));
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
    EXPECT_TRUE(db.searchByIndex(12345));
}

TEST_F(DatabaseTest, SearchByIndex_NonExistingIndex)
{
    EXPECT_FALSE(db.searchByIndex(12));
}

TEST_F(DatabaseTest, SearchByPesel_ExistingPesel)
{
    EXPECT_TRUE(db.searchByPesel("1234567890"));
}

TEST_F(DatabaseTest, SearchByPesel_NonExistingPesel)
{
    EXPECT_FALSE(db.searchByPesel("12345678910"));
}

TEST_F(DatabaseTest, SearchByGender_ExistingGender)
{
    EXPECT_TRUE(db.searchByGender(Gender::Male));
}
