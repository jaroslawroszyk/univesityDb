#include <gtest/gtest.h>
#include "Database.hpp"
#include "Student.hpp"
#include <tuple>

namespace
{
    const std::vector<Student> students{
        {"Adam",
         "Nowak",
         "ul.Bogatynska 12 00-201 Radom",
         123456,
         "12345678912",
         Gender::Male},
        {"Ania",
         "Kos",
         "ul.Bogatynska 12 00-201 Radom",
         6951,
         "1695678912",
         Gender::Female} };

    void fillDatabase(Database& db)
    {
        for (const auto& st : students)
        {
            db.add(st);
        }
    }

    template <typename... Students>
    void initDatabase(Database& db, const Students &...stud)
    {
        (db.add(stud), ...);
    }

    Student none{
        "none",
        "none",
        "none",
        1111,
        "24142",
        Gender::None };
    Student Ania{
        "Ania",
        "Kos",
        "ul.Bogatynska 12 00-201 Radom",
        6951,
        "24090833676",
        Gender::Female };
} // namespace

struct DatabaseTest : ::testing::Test
{
    Database db;
};

// TEST_F(DatabaseTest, DisplayEmtyDatabase)
//{
//     auto content = db.show();
//     auto expected = "";
//     EXPECT_EQ(content, expected);
// }

// TEST_F(DatabaseTest, DisplayNonEmptyDatabase)
//{
//     fillDatabase(db);
//     auto content = db.show();
//     auto expected = "Adam Nowak; ul.Bogatynska 12 00-201 Radom; 123456; 12345678912; Male";
//     EXPECT_EQ(content, expected);
// }

// TEST_F(DatabaseTest, CheckDuplicates)
//{
//     fillDatabase(db);
//     fillDatabase(db);
//     auto content = db.show();
//     auto expected = "Adam Nowak; ul.Bogatynska 12 00-201 Radom; 123456; 12345678912; Male";
//     EXPECT_EQ(content, expected);
// }

// TEST_F

TEST_F(DatabaseTest, DisplayFemaleStudent)
{
    db.add(Ania);

    //    auto content = db.show();
    ////    auto expected = "Ania Kos; ul.Bogatynska 12 00-201 Radom; 6951; 1695678912; Female";
    //    EXPECT_EQ(,expected);
}


TEST_F(DatabaseTest, searchInDatabaseIdx)
{
    db.initDatabase(db, none, Ania);
    EXPECT_TRUE(db.searchByIndex(1111));
    EXPECT_TRUE(db.searchByIndex(6951));
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

TEST_F(DatabaseTest, SearchByPesel)
{
    db.add(Ania);
    EXPECT_TRUE(db.searchByPesel("24090833676"));
}

