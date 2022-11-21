#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"
#include "Gender.h"
#include "PeselChecker.hpp"
#include <tuple>

namespace
{
    const std::vector<Student> student
    {
    	{
    		"Adam",
    		"Nowak",
    		"ul.Bogatynska 12 00-201 Radom",
    		123456,
    		"12345678912",
    		Gender::Male
    	},
        {
            "Ania",
            "Kos",
            "ul.Bogatynska 12 00-201 Radom",
            6951,
            "1695678912",
            Gender::Female
        }
    };

    void fillDatabase(Database &db)
    {
        for (const auto &st : student)
        {
            db.add(st);
        }
    }
} // namespace

struct DatabaseTest : ::testing::Test
{
    Database db;
};

TEST_F(DatabaseTest, DisplayEmtyDatabase)
{
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNonEmptyDatabase)
{
    fillDatabase(db);
    auto content = db.show();
    auto expected = "Adam Nowak; ul.Bogatynska 12 00-201 Radom; 123456; 12345678912; Male";
    EXPECT_EQ(content, expected);
    db.display();
}

TEST_F(DatabaseTest, CheckDuplicates)
{
    fillDatabase(db);
    fillDatabase(db);
    auto content = db.show();
    auto expected = "Adam Nowak; ul.Bogatynska 12 00-201 Radom; 123456; 12345678912; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayFemaleStudent)
{
    Student Ania{
            "Ania",
            "Kos",
            "ul.Bogatynska 12 00-201 Radom",
            6951,
            "1695678912",
            Gender::Female
    };
    db.add(Ania);

    auto content = db.show();
    auto expected = "Ania Kos; ul.Bogatynska 12 00-201 Radom; 6951; 1695678912; Female";
    EXPECT_EQ(content,expected);
    db.display();
}

TEST_F(DatabaseTest, DisplayNoneStudent)
{
    Student none{
            "none",
            "none",
            "none",
            1111,
            "24142",
            Gender::None
    };
    db.add(none);
}

TEST_F(DatabaseTest, SearchBySurname)
{
    fillDatabase(db);
    EXPECT_TRUE(db.searchBySurname("Nowak"));
}

TEST_F(DatabaseTest, CantFindStudentWithGivenSurname)
{
    fillDatabase(db);
    EXPECT_FALSE(db.searchBySurname("Piot"));
}

TEST_F(DatabaseTest, SearchByName)
{
    fillDatabase(db);
    EXPECT_TRUE(db.searchByName("Adam"));
}

TEST_F(DatabaseTest, SearchByIndexAdam)
{
    fillDatabase(db);
    EXPECT_TRUE(db.searchByIndex(123456));
}

struct PeselFixture : public ::testing::TestWithParam<std::tuple<std::string, bool>>
{
};

TEST_P(PeselFixture, checkCorrectPesels)
{
    auto [pesel, expected] = GetParam();
    EXPECT_EQ(checkPesel(pesel), expected);
}

INSTANTIATE_TEST_CASE_P(
    PeselFixtureTests,
    PeselFixture,
    ::testing::Values(
        std::make_tuple("24090833676", true),
        std::make_tuple("12345678901", false)));