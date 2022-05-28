#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"
#include "Gender.h"

struct DatabaseTest : ::testing::Test
{
    Database db;
};

TEST_F(DatabaseTest, DisplayEmtyDatabase)
{
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content,expected);
}

TEST_F(DatabaseTest, DisplayNonEmptyDatabase)
{
     Student adam{
        "Adam",
        "Nowak",
        "ul.Bogatynska 12 00-201 Radom",
        123456,
        "12345678912",
        Gender::Male
    };
    db.add(adam);

    auto content = db.show();
    auto expected = "Adam Nowak; ul.Bogatynska 12 00-201 Radom; 123456; 12345678912; Male";
    EXPECT_EQ(content,expected);
    db.display();
}

TEST_F(DatabaseTest,CheckDuplicates)
{
    Student adam{
            "Adam",
            "Nowak",
            "ul.Bogatynska 12 00-201 Radom",
            123456,
            "12345678912",
            Gender::Male
    };
    db.add(adam);
    db.add(adam);

    auto content = db.show();
    auto expected = "Adam Nowak; ul.Bogatynska 12 00-201 Radom; 123456; 12345678912; Male";
    EXPECT_EQ(content,expected);
}

TEST_F(DatabaseTest,DisplayFemaleStudent)
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

TEST_F(DatabaseTest,DisplayNoneStudent)
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

    auto content = db.show();
    auto expected = "none none; none; 1111; 24142; None";
    EXPECT_EQ(content,expected);
    db.display();
}
