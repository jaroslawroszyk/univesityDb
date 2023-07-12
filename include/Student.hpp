#pragma once
#include "Gender.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <compare>
#include <tuple>

class Student
{
public:
    Student(std::string, std::string, std::string, int, std::string, Gender);

    auto operator<=>(const Student& other) const = default;
    [[nodiscard]] auto show() const->std::string;
    [[nodiscard]] auto getName() const ->const std::string&;
    [[nodiscard]] auto getSurname() const ->const std::string&;
    [[nodiscard]] auto getAddress() const ->const std::string&;
    [[nodiscard]] auto getIndex() const -> int;
    [[nodiscard]] auto getPesel() const -> const std::string&;
    [[nodiscard]] auto getGender() const -> const Gender&;

    friend auto operator<<(std::ostream&, const Student&)->std::ostream&;

private:
    std::string name;
    std::string surname;
    std::string address;
    int indexNumber;
    std::string pesel;
    Gender gender;
};
