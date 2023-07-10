#pragma once
#include "Student.hpp"
#include <string>
#include <vector>

namespace Utils
{
    inline auto print(const Student&, std::ostream&) -> void;

    auto checkPesel(std::string) -> bool;

    auto printStudent(const Student&) -> void;

    auto trim(const std::string&) -> std::string;

} // namespace Utils
