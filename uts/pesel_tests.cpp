#include <gtest/gtest.h>
#include "PeselChecker.hpp"
#include <tuple>

struct PeselFixture : public ::testing::TestWithParam<std::tuple<std::string, bool>>
{
};

TEST_P(PeselFixture, isCorrectPesel)
{
    auto [pesel, expected] = GetParam();
    EXPECT_EQ(checkPesel(pesel), expected);
}

INSTANTIATE_TEST_SUITE_P(
    PeselFixtureTests,
    PeselFixture,
    ::testing::Values(
        std::make_tuple("24090833676", true),
        std::make_tuple("12345678901", false)));