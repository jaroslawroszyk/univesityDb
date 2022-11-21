#pragma once
#include <vector>
#include "student.hpp"
#include "Gender.h"
#include <algorithm>

class Database
{
public:
    std::vector<Student> add(const Student &s);
    void display() const;
    std::string show() const;
    std::size_t getNumberOfStudents() const { return students.size();};
    bool searchByName(const std::string&);
    bool searchBySurname(const std::string&) const;
    bool searchByIndex(int);

private:
    std::vector<Student> students;
};