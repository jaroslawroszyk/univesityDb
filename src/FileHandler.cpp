#include "Database.hpp"
#include "FileHandler.hpp"
#include "Student.hpp"
#include "Utils.hpp"
#include <algorithm> 
#include <fstream>
#include <sstream>

FileHandler::FileHandler(const std::string& filename, Mode mode)
    : filename(filename), fileMode(mode)
{
    if (fileMode == Mode::Write)
    {
        fileStream.open(filename);
        if (!fileStream)
            throw std::runtime_error{ "Failed to open the file for writing" };
    }
    else if (fileMode == Mode::Read)
    {
        fileReadStream.open(filename);
        if (!fileReadStream)
            throw std::runtime_error{ "Failed to open the file for reading" };
    }
}

FileHandler::~FileHandler()
{
    if (fileStream.is_open())
        fileStream.close();
    if (fileReadStream.is_open())
        fileReadStream.close();
}

void FileHandler::writeToCsvFile(const Database& db)
{
    if (fileMode != Mode::Write)
        throw std::runtime_error{ "Cannot write to the file. Invalid file mode." };

    fileStream << "Name, Surname, Address, Pesel, Gender\n";
    for (const auto& student : db.getStudents())
    {
        fileStream << student.getName() << ", "
            << student.getSurname() << ", "
            << student.getAddress() << ", "
            << student.getPesel() << ", "
            << GenderToString(student.getGender()) << "\n";
    }
}

void FileHandler::readDbFromFile(Database& db)
{
    if (fileMode != Mode::Read)
        throw std::runtime_error{ "Cannot read from the file. Invalid file mode." };

    std::string tmp{};
    std::getline(fileReadStream, tmp);

    while (std::getline(fileReadStream, tmp))
    {
        std::istringstream iss(tmp);
        std::string name, surname, address, pesel, genderStr;
        int indexNumber;

        if (std::getline(iss, name, ',') &&
            std::getline(iss, surname, ',') &&
            std::getline(iss, address, ',') &&
            std::getline(iss, pesel, ',') &&
            std::getline(iss, genderStr, ','))
        {
            genderStr = Utils::trim(genderStr);

            Gender gender = StringToGender(genderStr);

            Student student(name, surname, address, indexNumber, pesel, gender);
            db.add(student);
        }
    }
}
