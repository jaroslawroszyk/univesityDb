#pragma once
#include <iostream>

enum class Gender
{
    Male,
    Female,
    Nonbinary,
    Other
};

inline std::ostream& operator<<(std::ostream& os, Gender gender)
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

inline const char* GenderToString(Gender e)
{
    switch (e)
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