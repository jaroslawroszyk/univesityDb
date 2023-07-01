#include <gtest/gtest.h>
#include "Database.hpp"
#include "Student.hpp"
#include "Utils.hpp"

namespace
{
    const std::vector<Student> students{
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
        } };

    void fillDatabase(Database& db)
    {
        for (const auto& st : students)
        {
            db.add(st);
        }
    }

    Student Ania{
        "Aneta",
        "Kos",
        "ul.Bogatynska 12 00-201 Radom",
        6951,
        "24090833676",
        Gender::Female };

    Student Zosia{
        "Zosia",
        "Zosinska",
        "ul. 00-201 Radom",
        69,
        "24090833676",
        Gender::Female };
} // namespace

struct DatabaseTest : ::testing::Test
{
    Database db;

    void SetUp() override
    {
        fillDatabase(db);
    }
};

TEST_F(DatabaseTest, AddStudent_DoesNotDuplicate)
{
    db.add(Ania);

    std::size_t originalSize = db.getSize();

    db.add(Ania);

    std::size_t newSize = db.getSize();

    EXPECT_TRUE(originalSize == newSize);
}

TEST_F(DatabaseTest, SearchByName_ReturnsTrueIfExists)
{
    EXPECT_TRUE(db.searchByName("Adam"));
}

TEST_F(DatabaseTest, SearchBySurname_ReturnsTrueIfExists)
{
    EXPECT_TRUE(db.searchBySurname("Nowak"));
}

TEST_F(DatabaseTest, SearchByIndex_ReturnsTrueIfExists)
{
    db.initDatabase(db, Ania);
    EXPECT_TRUE(db.searchByIndex(6951));
}

TEST_F(DatabaseTest, SearchByPesel_ReturnsTrueIfExists)
{
    db.add(Ania);
    EXPECT_TRUE(db.searchByPesel("24090833676"));
}

TEST_F(DatabaseTest, SearchBySurname_ReturnsFalseIfNotExists)
{
    fillDatabase(db);
    EXPECT_FALSE(db.searchBySurname("Piot"));
}

TEST_F(DatabaseTest, DeleteByIndex_RemovesStudentIfExists)
{
    bool isDeleted = db.deleteByIndex(6951);

    EXPECT_TRUE(isDeleted);
    EXPECT_EQ(db.getSize(), 1);
    EXPECT_FALSE(db.searchByIndex(6951));
}
