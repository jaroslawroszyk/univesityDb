#include "Gender.hpp"
#include "Student.hpp"
#include <tuple>

Student::Student(
    std::string name,
    std::string surname,
    std::string address,
    int indexNumber,
    std::string Pesel,
    Gender gender) : name(name), surname(surname), address(address), indexNumber(indexNumber), pesel(Pesel)
    , gender(gender)
{
}

auto Student::show() const -> std::string
{
    return name + " " + surname + "; " + address + "; " + std::to_string(indexNumber) + "; " + pesel + "; " +
        GenderToString(gender);
}

auto Student::getName() const -> const std::string& { return name; }
auto Student::getSurname() const -> const std::string& { return surname; }
auto Student::getAddress() const -> const std::string& { return address; }
auto Student::getIndex() const -> int { return indexNumber; }
auto Student::getPesel() const -> const std::string& { return pesel; }
auto Student::getGender() const -> const Gender& { return gender; }

auto operator<<(std::ostream& os, const Student& student) -> std::ostream&
{
    os << student.name << " " << student.surname << " " << student.address << " " << student.indexNumber << " "
        << student.pesel << " " << student.gender;
    return os;
}
