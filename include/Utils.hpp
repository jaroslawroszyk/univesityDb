#pragma once
#include <vector>
#include <iostream>
#include "Student.hpp"
#include <string>

namespace Utils
{
    inline void print(const Student& student, std::ostream& os);

    inline void print2(const Student& student, std::ostream& os);

    bool checkPesel(std::string pesel);

    void printStudent(const Student& s);


} // namespace Utils