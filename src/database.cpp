#include "../include/database.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>

namespace
{
    template <typename T>
    bool hasDuplicates(const std::vector<T> &arr)
    {
        for (auto it = arr.begin(); it != arr.end(); ++it)
            if (std::find(std::next(it), arr.end(), *it) != arr.end())
                return true;
        return false;
    }

    template <typename T>
    void print(const T &vec)
    {
        for (const auto &el : vec)
        {
            std::cout << el << ' ';
        }
    }
}

void Database::add(const Student &student)
{
    if (not students.empty() or not hasDuplicates(students))
    {
        students.push_back(student);
    }
}

void Database::add(Student &&s)
{
    students.push_back(s);
}

std::vector<Student> Database::show() const
{
    std::vector<Student> result{};
    for (const auto &student : students)
    {
        result.push_back(student);
    }
    print(result);

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
    for (const auto &student : students)
    {
        if (student.getName() == name)
            return true;
    }
    return false;
        // return std::ranges::find(students, name, &Student::getName) != students.end();
}

bool Database::searchBySurname(const std::string &surname) const
{
    for (const auto &student : students)
    {
        if (student.getSurname() == surname)
            return true;
    }
    return false;
    //   return std::ranges::find(students, surname, &Student::getSurname) != students.end();
}

bool Database::searchByIndex(int index)
{
    for (const auto &student : students)
    {
        if (student.getIndex() == index)
            return true;
    }
    return false;
    // return std::ranges::find(students, index, &Student::getIndex) != students.end();
}
