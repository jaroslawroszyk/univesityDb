#include "Student.hpp"
#include "Database.hpp"
#include "FileHandler.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
        if (argc < 2)
        {
                std::cout << "Usage: ./studentDb --write or ./studentDb --read" << std::endl;
                return 0;
        }

        Database db;

        if (std::string(argv[1]) == "--write")
        {
                FileHandler fileHandler("students.csv", Mode::Write);
                Student none{
                    "none",
                    "none",
                    "n2one",
                    1111,
                    "24142",
                    Gender::Nonbinary
                };
                db.add(none);
                fileHandler.writeToCsvFile(db);
                db.show();
        }
        else if (std::string(argv[1]) == "--read")
        {
                FileHandler fileHandler("students.csv", Mode::Read);
                fileHandler.readDbFromFile(db);
                db.show();
        }
        else
        {
                std::cout << "Invalid command. Usage: ./studentDb --write or ./studentDb --read" << std::endl;
        }

        return 0;
}
