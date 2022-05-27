#include "student.hpp"

Student::Student(
    std::string name,
    std::string surname,
    std::string addres,
    int indexNumber,
    std::string Pesel,
    Gender gender) : name(name), surname(surname), addres(addres), indexNumber(indexNumber), Pesel(Pesel), gender(gender)
{
}

std::string Student::show() const
{
    return name + " " + surname + "; " + addres + "; " + std::to_string(indexNumber) + "; " + Pesel + "; " + "Male";
}
