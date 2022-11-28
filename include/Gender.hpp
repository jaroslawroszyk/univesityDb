#pragma once
#include <iostream>

enum class Gender
{
    Male ,
    Female ,
    None
};

inline std::ostream &operator<<(std::ostream &os , Gender gender)
{
    switch (gender)
    {
        case Gender::Male :
            return os << "Male";
        case Gender::Female :
            return os << "Female";
        case Gender::None :
            return os << "None";
        default:
            return os << "?? Panic ??";
    }
}

inline const char* GenderToString(Gender e)
{
    switch (e)
    {
        case Gender::Male :
            return "Male";
        case Gender::Female :
            return "Female";
        case Gender::None :
            return  "None";
    }
    return "Ops";
}