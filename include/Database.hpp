#pragma once

#include "Student.hpp"
#include "Gender.hpp"
#include <vector>
#include <algorithm>
#include <string_view>

class Database final
{
public:
    Database() = default;
    void add(const Student&);
    void add(Student&&);
    void show() const;
    void printByGender(Gender) const;

    std::size_t getSize() const;
    bool searchByName(const std::string&);
    bool searchBySurname(const std::string&) const;
    bool searchByIndex(int);
    bool searchByPesel(const std::string&);

    bool deleteByIndex(int);

    template<typename ... Students>
    void initDatabase(Database& db, Students &...stud)
    {
        (db.add(stud), ...);
    }

    auto getStudents() const
    {
        return students;
    }
private:
    std::vector<Student> students;
};
