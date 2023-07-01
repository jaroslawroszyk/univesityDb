#pragma once
#include <vector>
#include <iostream>

namespace Utils
{
    template <typename T>
    void print(const T& vec)
    {
        for (const auto& el : vec)
        {
            std::cout << el << ' ';
        }
    }

    template <typename T>
    bool hasDuplicates(const std::vector<T>& arr)
    {
        for (auto it = arr.begin(); it != arr.end(); ++it)
            if (std::find(std::next(it), arr.end(), *it) != arr.end())
                return true;
        return false;
    }
} // namespace Utils