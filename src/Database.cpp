#include "Database.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>

void Database::add(const Student& student)
{
    if (not students.empty() or not Utils::hasDuplicates(students))
    {
        students.push_back(student);
    }
}

void Database::add(Student&& s)
{
    students.push_back(s);
}

std::vector<Student> Database::show() const
{
    std::vector<Student> result{};
    for (const auto& student : students)
    {
        result.push_back(student);
    }
    Utils::print(result);

    return result;
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

std::size_t Database::getNumberOfStudents() const { return students.size(); };
