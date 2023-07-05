#pragma once
#include "Gender.hpp"
#include <iostream>
#include <string>
#include <vector>

class Student
{
public:
    Student(std::string, std::string, std::string, int, std::string, Gender);

    bool operator==(const Student& other) const;
    bool operator==(const Student&& other) const;
    [[nodiscard]] std::string show() const;
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const std::string& getSurname() const;
    [[nodiscard]] const std::string& getAddress() const;
    [[nodiscard]] int getIndex() const;
    [[nodiscard]] const std::string& getPesel() const;
    [[nodiscard]] const Gender& getGender() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& st);

private:
    std::string name;
    std::string surname;
    std::string addres;
    int indexNumber;
    std::string pesel;
    Gender gender;
};
