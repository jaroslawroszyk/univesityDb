#pragma once
#include <string>

enum class Gender
{
    Male,
    Female,
    None
};

class Student
{
public:
    Student(std::string name, std::string surname, std::string addres, int indexNumber, std::string Pesel, Gender gender);
    std::string show() const;

private:
    std::string name;
    std::string surname;
    std::string addres;
    int indexNumber;
    std::string Pesel;
    Gender gender;
};