#include <gtest/gtest.h>
#include "auxiliaries.hpp"

TEST(practice2, parseArguments)
{
    int argc = 0;
    char **argv = 0;
    int res = parseArguments(argc, argv);

    EXPECT_EQ(0, res);
}