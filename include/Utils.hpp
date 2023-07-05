#pragma once
#include "Student.hpp"
#include <string>
#include <vector>

namespace Utils
{
    inline void print(const Student& student, std::ostream& os);

    inline void print2(const Student& student, std::ostream& os);

    bool checkPesel(std::string pesel);

    void printStudent(const Student& s);


    std::string trim(const std::string& str);

} // namespace Utils
