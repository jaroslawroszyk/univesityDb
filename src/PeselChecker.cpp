#include "PeselChecker.hpp"
#include <vector>

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