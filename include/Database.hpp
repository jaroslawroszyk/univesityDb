#pragma once

#include "Student.hpp"
#include "Gender.hpp"
#include <vector>
#include <algorithm>

class Database
{
public:
    void add(const Student&);
    void add(Student&&);
    void show() const;
    void printByGender(Gender) const;

    std::size_t getSize() const;
    bool searchByName(const std::string&);
    bool searchBySurname(const std::string&) const;
    bool searchByIndex(int);
    bool searchByPesel(const std::string&);

    bool deleteByIndex(int idx)
    {
        auto it = std::find_if(students.begin(), students.end(), [idx](const Student& student)
            {
                return student.getIndex() == idx;
            });

        if (it != students.end())
        {
            students.erase(it);
            return true;
        }
        return false;
    }

    template<typename ... Students>
    void initDatabase(Database& db, Students &...stud)
    {
        (db.add(stud), ...);
    }

private:
    std::vector<Student> students;
};

/*
todo: displaying only male or female students
*/