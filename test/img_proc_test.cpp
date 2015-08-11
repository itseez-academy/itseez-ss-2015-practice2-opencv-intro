#include <gtest/gtest.h>
#include "img_proc.hpp"

TEST(practice2, median_filter_test)
{
    std::string input = "./testdata/image.jpg";
    std::string expOutput = "./testdata/image_median_1.jpg";

    Mat src, expDst, dst; 
    getFrame(input, src);
    getFrame(expOutput, expDst);
    if (expDst.empty())
    {
        FAIL() << "Can't read" + expOutput + " image";
    }

    Mat diff = abs(expDst - dst);
    Mat mask = diff.reshape(1) > 1;

    EXPECT_EQ(0, countNonZero(mask));

}
