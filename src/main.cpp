#include "Student.hpp"
#include "Database.hpp"
#include "FileHandler.hpp"
#include "Logger/Printer.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
        if (argc < 2)
        {
                std::cout << "Usage: ./studentDb --write or ./studentDb --read" << std::endl;
                return 0;
        }

        Database db{};

        if (std::string(argv[1]) == "--write")
        {
                FileHandler fileHandler("students.csv", Mode::Write);
                Student none{ "John","Doe","123 Main St",12345,"1234567890",Gender::Male };
                Student Men{ "Jane", "Smith", "456 Elm St", 54321, "0987654321", Gender::Female };

                db.addStudents(none, Men);

                fileHandler.writeToCsvFile(db);

                // db.printByGender(Gender::Male);
                std::vector<Student> students{ none,Men };
                db.deleteByPesel(none.getPesel());
                db.show();
                // std::cout << makePrintable(students);
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
