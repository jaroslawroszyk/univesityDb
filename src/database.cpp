#include "database.hpp"
#include <iostream>
#include <string>

void Database::add(const Student &s)
{
   students.push_back(s);
}

void Database::display() const
{
    std::cout << show();
}

std::string Database::show() const
{
    std::string result = "";
    for (auto &&student : students)
    {
        result += student.show();
    }
    return result;
}