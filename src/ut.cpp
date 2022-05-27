#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

TEST(CheckStructure, CanAddStudentToDatabase)
{
    Student adam{
        "Adam",
        "Nowak",
        "ul.Bogatynska 12 00-201 Radom",
        123456,
        "12345678912",
        Gender::Male
    };

    Database db;
    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
}