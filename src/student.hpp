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
    [[nodiscard]] std::string show() const;
    [[nodiscard]] const std::string& getName() const { return name;}
    [[nodiscard]] const std::string& getSurname() const { return surname;}
    [[nodiscard]] int getIndex() const { return indexNumber; }
private:
    std::string name;
    std::string surname;
    std::string addres;
    int indexNumber;
    std::string Pesel;
    Gender gender;
};
