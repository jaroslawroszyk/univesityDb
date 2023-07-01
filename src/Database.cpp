#include "Database.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>
#include "Utils.hpp"

// void Database::add(const Student& student)
// {
//     if (std::find_if(students.begin(), students.end(), [&](const Student& s)
//         {
//             return s == student;
//         }) == students.end())
//     {
//         students.push_back(student);
//     }
// }

void Database::add(const Student& student)
{
    if (std::ranges::find(students, student) == students.end())
    {
        students.push_back(student);
    }
}

void Database::add(Student&& student)
{
    if (std::ranges::find(students, student) == students.end())
    {
        students.push_back(std::move(student));
    }
}

void Database::printByGender(Gender gender) const
{
    for (auto student : students)
    {
        if (student.getGender() == gender)
        {
            std::cout << student.show() << std::endl;
        }
    }
}

void Database::show() const
{
    for (const auto& student : students)
    {
        Utils::printStudent(student);
    }
}



bool Database::searchByPesel(const std::string& pesel)
{
    return std::ranges::find(students, pesel, &Student::getPesel) != students.end();
}

bool Database::searchByName(const std::string& name)
{
    return std::ranges::find(students, name, &Student::getName) != students.end();
}

bool Database::searchBySurname(const std::string& surname) const
{
    return std::ranges::find(students, surname, &Student::getSurname) != students.end();
}

bool Database::searchByIndex(int index)
{
    return std::ranges::find(students, index, &Student::getIndex) != students.end();
}

std::size_t Database::getSize() const { return students.size(); };
