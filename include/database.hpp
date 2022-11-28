#pragma once

#include <vector>
#include "student.hpp"
#include "../include/Gender.hpp"
#include <algorithm>

class Database
{
public:
    void add(const Student &s);

    void add(Student &&s);

    std::vector<Student> show() const;

    std::size_t getNumberOfStudents() const { return students.size(); };

    bool searchByName(const std::string &);

    bool searchBySurname(const std::string &) const;

    bool searchByIndex(int);

    template<typename ... Students>
    void initDatabase(Database &db, Students &...stud)
    {
        (db.add(stud), ...);
    }

private:
    std::vector<Student> students;
};