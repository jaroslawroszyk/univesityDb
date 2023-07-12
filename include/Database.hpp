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
    auto printByGender(const Gender&) const -> void;

    template<typename... Args>
    auto addStudents(Args&&... students) -> void
    {
        (add(std::forward<Args>(students)), ...);
    }

    auto searchByName(const std::string&) const->bool;
    auto searchBySurname(const std::string&) const->bool;
    auto searchByIndex(int) const->bool;
    auto searchByPesel(const std::string&) const->bool;
    auto searchByGender(const Gender&) const->bool;

    auto deleteBySurname(const std::string&) -> bool;
    auto deleteByIndex(int) -> bool;
    auto deleteByPesel(const std::string&) -> bool;

    template<typename ... Students>
    auto initDatabase(Database& db, Students &...students) -> void
    {
        (db.add(students), ...);
    }

    std::size_t getSize() const;
    auto getStudents() const->std::vector<Student>;

private:
    std::vector<Student> students;
};
