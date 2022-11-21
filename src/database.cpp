#include "database.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <array>

template <typename T>
bool hasDuplicates(const std::vector<T> &arr)
{
    for (auto it = arr.begin(); it != arr.end(); ++it)
        if (std::find(std::next(it), arr.end(), *it) != arr.end())
            return true;
    return false;
}

std::vector<Student> Database::add(const Student &s)
{
    if (students.empty())
    {
        if (hasDuplicates(students))
            return students;
        else if (!hasDuplicates(students))
            students.push_back(s);
    }

    return students;
}

void Database::display() const
{
    std::cout << show();
}

std::string Database::show() const
{
    std::string result{};
    for (auto &&student : students)
    {
        result += student.show();
    }
    return result;
}

/*
todo:
serach by pesel
sort by pesel
sort by surname
*/

bool Database::searchByName(const std::string &name)
{
    return std::ranges::find(students, name, &Student::getName) != students.end();
}


bool Database::searchBySurname(const std::string &surname) const
{
  return std::ranges::find(students, surname, &Student::getSurname) != students.end();
}

bool Database::searchByIndex(int index)
{
    return std::ranges::find(students, index, &Student::getIndex) != students.end();
}
