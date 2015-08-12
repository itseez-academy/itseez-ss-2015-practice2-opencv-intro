#include <gtest/gtest.h>
#include "auxiliaries.hpp"

TEST(practice2, parse_empty_arguments)
{
    int argc = 0;
    const char **argv = 0;
    Parameters params;
    int res = parseArguments(argc, argv, params);

    EXPECT_EQ(1, res);
}

TEST(practice2, parse_incorrect_arguments)
{
    int argc = 2;
    const char *argv[] = { "", "image.jpg" };
    Parameters params;
    int res = parseArguments(argc, argv, params);

    EXPECT_EQ(0, res);
}
