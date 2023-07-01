#include "Utils.hpp"
#include <vector>
#include <iostream>
#include "Student.hpp"
#include <string>

namespace Utils
{
    // template <typename T>
    // void print(const T& vec)
    // {
    //     for (const auto& el : vec)
    //     {
    //         std::cout << el << ' ';
    //     }
    // }

    inline void print(const Student& student, std::ostream& os)
    {
        os << "Name: " << student.getName() << std::endl;
        os << "Surname: " << student.getSurname() << std::endl;
        os << "Address: " << student.getAdress() << std::endl;
        os << "Index: " << student.getIndex() << std::endl;
        os << "Gender: " << student.getGender() << std::endl;
        os << "-------------------------" << std::endl;
    }
    void printStudent(const Student& s)
    {
        std::cout << "-----------------------------------\n";
        std::cout << "Name " << s.getName() << std::endl;
        std::cout << "surname " << s.getSurname() << std::endl;
        std::cout << "addres " << s.getAdress() << std::endl;
        std::cout << "indexNumber " << s.getIndex() << std::endl;
        std::cout << "pesel " << s.getPesel() << std::endl;
        std::cout << "gender " << s.getGender() << std::endl;
        std::cout << "-----------------------------------\n";
    }
    inline void print2(const Student& student, std::ostream& os)
    {
        os << "Name: " << student.getName() << std::endl;
        os << "Surname: " << student.getSurname() << std::endl;
        os << "Address: " << student.getAdress() << std::endl;
        os << "Index: " << student.getIndex() << std::endl;
        os << "Gender: " << student.getGender() << std::endl;
        os << "-------------------------" << std::endl;
    }

    bool checkPesel(std::string pesel)
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


} // namespace Utils