#pragma once
#include "Gender.h"
#include <string>
#include <iostream>
#include <vector>

class Student
{
public:
    Student(std::string name , std::string surname , std::string addres , int indexNumber , std::string Pesel ,
            Gender gender);

    bool operator==(const Student &other) const;
    std::string show() const;

private:
    std::string name;
    std::string surname;
    std::string addres;
    int indexNumber;
    std::string Pesel;
    Gender gender;
};
