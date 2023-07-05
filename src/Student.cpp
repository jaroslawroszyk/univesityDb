#include "Gender.hpp"
#include "Student.hpp"
#include <tuple>

Student::Student(
    std::string name,
    std::string surname,
    std::string addres,
    int indexNumber,
    std::string Pesel,
    Gender gender) : name(name), surname(surname), addres(addres), indexNumber(indexNumber), pesel(Pesel)
    , gender(gender)
{
}

std::string Student::show() const
{
    return name + " " + surname + "; " + addres + "; " + std::to_string(indexNumber) + "; " + pesel + "; " +
        GenderToString(gender);
}

bool Student::operator==(const Student& other) const
{
    return std::tie(name, surname, addres, indexNumber, pesel, gender) ==
        std::tie(other.name, other.surname, other.addres, other.indexNumber, other.pesel, other.gender);
}

bool Student::operator==(const Student&& other) const
{
    return std::tie(name, surname, addres, indexNumber, pesel, gender) ==
        std::tie(other.name, other.surname, other.addres, other.indexNumber, other.pesel, other.gender);
}

const std::string& Student::getName() const { return name; }
const std::string& Student::getSurname() const { return surname; }
const std::string& Student::getAddress() const { return addres; }
int Student::getIndex() const { return indexNumber; }
const std::string& Student::getPesel() const { return pesel; }
const Gender& Student::getGender() const { return gender; }

std::ostream& operator<<(std::ostream& os, const Student& st)
{
    os << st.name << " " << st.surname << " " << st.addres << " " << st.indexNumber << " "
        << st.pesel << " " << st.gender;
    return os;
}