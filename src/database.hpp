#pragma once
#include <vector>
#include "student.hpp"
#include "Gender.h"

class Database
{
public:
    std::vector<Student> add(const Student &s);
    void display() const;
    std::string show() const;
//    bool searchBySurname(Database s,std::string);
private:
    std::vector<Student> students;
};