#include <tuple>
#include "student.hpp"
#include "Gender.h"

Student::Student(
        std::string name ,
        std::string surname ,
        std::string addres ,
        int indexNumber ,
        std::string Pesel ,
        Gender gender) : name(name) , surname(surname) , addres(addres) , indexNumber(indexNumber) , Pesel(Pesel)
                         , gender(gender)
{
}

std::string Student::show() const
{
    return name + " " + surname + "; " + addres + "; " + std::to_string(indexNumber) + "; " + Pesel + "; " +
           GenderToString(gender);
}

bool Student::operator==(const Student &other) const
{
    return std::tie(name , surname , addres , indexNumber , Pesel , gender) ==
           std::tie(other.name , other.surname , other.addres , other.indexNumber , other.Pesel , other.gender);
}

