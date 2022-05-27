#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DatabaseTest : ::testing::Test
{
    Database db;
};

TEST_F(DatabaseTest, CanAddStudentToDatabase)
{
    Student adam{
        "Adam",
        "Nowak",
        "ul.Bogatynska 12 00-201 Radom",
        123456,
        "12345678912",
        Gender::Male
    };

    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
}

TEST_F(DatabaseTest, DisplayEmtyDatabase)
{
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content,expected);
}

// TEST(DisplayDatabase, DisplayNonEmptyDatabase)
// {
//     Database db;

//      Student adam{
//         "Adam",
//         "Nowak",
//         "ul.Bogatynska 12 00-201 Radom",
//         123456,
//         "12345678912",
//         Gender::Male
//     };
//     EXPECT_TRUE(db.add(adam));

//     db.display();
// }

