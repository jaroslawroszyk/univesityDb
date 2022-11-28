#pragma once
#include "../include/Gender.hpp"
#include <string>
#include <iostream>
#include <vector>

class Student
{
public:
    Student(std::string name , std::string surname , std::string addres , int indexNumber , std::string Pesel ,
            Gender gender);

    bool operator==(const Student &other) const;
    bool operator==(const Student &&other) const;
    [[nodiscard]] std::string show() const;
    [[nodiscard]] const std::string& getName() const { return name;}
    [[nodiscard]] const std::string& getSurname() const { return surname;}
    [[nodiscard]] int getIndex() const { return indexNumber; }

    friend std::ostream& operator<<(std::ostream& os, const Student& st)
    {
        os << st.name << " " << st.surname << " " << st.addres << " " << st.indexNumber << " "
        << st.Pesel << " " << st.gender;
        return os;
    }

private:
    std::string name;
    std::string surname;
    std::string addres;
    int indexNumber;
    std::string Pesel;
    Gender gender;
};
