#pragma once
#include <iostream>
#include <tuple>
#include <ostream>

template <typename... Args>
auto makePrintable(Args&&... args)
{
    return std::make_tuple(std::forward<Args>(args)...);
}

template <typename Container>
auto makePrintable(const Container& container)
{
    return std::make_tuple(container);
}

template <typename... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& printable)
{
    std::apply([&os](const auto&... args) { ((os << args << "\n"), ...); }, printable);
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (const auto& element : vec)
    {
        os << element << "\n";
    }
    return os;
}
