#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

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
    // check adding the same person twice
    
    auto content = db.show();
    auto expected = "Adam Nowak; ul.Bogatynska 12 00-201 Radom; 123456; 12345678912; Male";
    EXPECT_EQ(content,expected);
    db.display();
}

