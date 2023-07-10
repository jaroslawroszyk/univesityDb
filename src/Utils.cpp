#include "Student.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace Utils
{

    inline auto print(const Student& student, std::ostream& os) -> void
    {
        os << "Name: " << student.getName() << std::endl;
        os << "Surname: " << student.getSurname() << std::endl;
        os << "Address: " << student.getAddress() << std::endl;
        os << "Index: " << student.getIndex() << std::endl;
        os << "Gender: " << student.getGender() << std::endl;
        os << "-------------------------" << std::endl;
    }

    auto printStudent(const Student& s) -> void
    {
        std::cout << "-----------------------------------\n";
        std::cout << "Name " << s.getName() << std::endl;
        std::cout << "surname " << s.getSurname() << std::endl;
        std::cout << "address " << s.getAddress() << std::endl;
        std::cout << "indexNumber " << s.getIndex() << std::endl;
        std::cout << "pesel " << s.getPesel() << std::endl;
        std::cout << "gender " << s.getGender() << std::endl;
        std::cout << "-----------------------------------\n";
    }

    auto checkPesel(std::string pesel) -> bool
    {
        if (pesel.size() != 11)
            return false;

        std::vector<int> weights = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };

        int sum = 0;
        for (size_t i = 0; i < 10; i++)
        {
            int digit = pesel[i] - '0';
            sum += digit * weights[i];
        }

        int controlDigit = (10 - (sum % 10)) % 10;
        int lastDigit = pesel[10] - '0';

        return controlDigit == lastDigit;
    }

    auto trim(const std::string& str) -> std::string
    {
        auto start = str.find_first_not_of(" \t\n\r\f\v");

        auto end = str.find_last_not_of(" \t\n\r\f\v");

        if (start == std::string::npos)
            return "";

        return str.substr(start, end - start + 1);
    }

} // namespace Utils
