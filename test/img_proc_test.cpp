#include <gtest/gtest.h>
#include "img_proc.hpp"

TEST(practice2, median_filter_test)
{
    std::string input = "./testdata/image.png";
    std::string expOutput = "./testdata/image_median_11.png";

    Mat src, expDst, dst; 
    getFrame(input, src);
    if (src.empty())
    {
        FAIL() << "Can't read" + input + " image";
    }
    getFrame(expOutput, expDst);
    if (expDst.empty())
    {
        FAIL() << "Can't read" + expOutput + " image";
    }

    if (processFrame(src, dst) != 0)
    {
        FAIL() << "Can't execute median filtering";
    }

    Mat diff = abs(expDst - dst);
    Mat mask = diff.reshape(1) > 1;

    EXPECT_EQ(0, countNonZero(mask));

}
