#pragma once
#include <iostream>

enum class Gender
{
    Male,
    Female,
    Nonbinary,
    Other
};

inline auto operator<<(std::ostream& os, Gender gender) -> std::ostream&
{
    switch (gender)
    {
    case Gender::Male:
        return os << "Male";
    case Gender::Female:
        return os << "Female";
    case Gender::Other:
        return os << "Other";
    case Gender::Nonbinary:
        return os << "Nonbinary";
    default:
        return os << "?? Panic ??";
    }
}

inline auto GenderToString(Gender gender) -> const char*
{
    switch (gender)
    {
    case Gender::Male:
        return "Male";
    case Gender::Female:
        return "Female";
    case Gender::Other:
        return "Other";
    case Gender::Nonbinary:
        return "Nonbinary";
    default:
        return "Panic!!";
    }
    return "Ops";
}

inline auto StringToGender(const std::string& str) -> Gender
{
    if (str == "Male")
        return Gender::Male;
    else if (str == "Female")
        return Gender::Female;
    else if (str == "Nonbinary")
        return Gender::Nonbinary;
    else if (str == "Other")
        return Gender::Other;
    else
        throw std::runtime_error("Invalid gender string");
}
