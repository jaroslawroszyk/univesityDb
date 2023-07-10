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
    auto add(const Student&) -> void;
    auto add(Student&&) -> void;
    auto show() const -> void;
    auto printByGender(Gender) const -> void;
    template<typename... Args>
    auto addStudents(Args&&... students) -> void
    {
        (add(std::forward<Args>(students)), ...);
    }

    std::size_t getSize() const;
    auto searchByName(const std::string&) const->bool;
    auto searchBySurname(const std::string&) const->bool;
    auto searchByIndex(int) const->bool;
    auto searchByPesel(const std::string&) const->bool;
    auto searchByGender(const Gender&) const->bool;

    auto deleteByIndex(int) -> bool;

    template<typename ... Students>
    auto initDatabase(Database& db, Students &...students) -> void
    {
        (db.add(students), ...);
    }

    auto getStudents() const
    {
        return students;
    }
private:
    std::vector<Student> students;
};
