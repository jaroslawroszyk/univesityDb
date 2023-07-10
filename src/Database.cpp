#include "Database.hpp"
#include "Gender.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <ranges>
#include <string>
#include <vector>

auto Database::add(const Student& student) -> void
{
    if (std::ranges::find(students, student) == students.end())
    {
        students.push_back(student);
    }
}

auto Database::add(Student&& student) -> void
{
    if (std::ranges::find(students, student) == students.end())
    {
        students.push_back(std::move(student));
    }
}

auto Database::printByGender(Gender gender) const -> void
{
    for (auto student : students)
    {
        if (student.getGender() == gender)
        {
            std::cout << student.show() << std::endl;
        }
    }
}

auto Database::show() const -> void
{
    for (const auto& student : students)
    {
        Utils::printStudent(student);
    }
}

auto Database::deleteByIndex(int index) -> bool
{
    auto it = std::find_if(students.begin(), students.end(), [index](const Student& student)
        {
            return student.getIndex() == index;
        });

    if (it != students.end())
    {
        students.erase(it);
        return true;
    }
    return false;
}

auto Database::searchByPesel(const std::string& pesel) const -> bool
{
    return std::ranges::find(students, pesel, &Student::getPesel) != students.end();
}

auto Database::searchByName(const std::string& name) const -> bool
{
    return std::ranges::find(students, name, &Student::getName) != students.end();
}

auto Database::searchBySurname(const std::string& surname) const -> bool
{
    return std::ranges::find(students, surname, &Student::getSurname) != students.end();
}

auto Database::searchByIndex(int index) const -> bool
{
    return std::ranges::find(students, index, &Student::getIndex) != students.end();
}

auto Database::searchByGender(const Gender& gender) const -> bool
{
    return std::ranges::find(students, gender, &Student::getGender) != students.end();
}

auto Database::getSize() const -> std::size_t { return students.size(); };
