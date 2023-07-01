#include <gtest/gtest.h>
#include "Utils.hpp"
#include <tuple>
using namespace Utils;

struct PeselFixture : public ::testing::TestWithParam<std::tuple<std::string, bool>>
{
};

TEST_P(PeselFixture, isCorrectPesel)
{
    auto [pesel, expected] = GetParam();
    EXPECT_EQ(Utils::checkPesel(pesel), expected);
}

INSTANTIATE_TEST_SUITE_P(
    PeselFixtureTests,
    PeselFixture,
    ::testing::Values(
        std::make_tuple("24090833676", true),
        std::make_tuple("12345678901", false)));