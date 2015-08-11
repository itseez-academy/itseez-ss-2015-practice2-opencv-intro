#include "img_proc.hpp"

int getFrame(const std::string &fileName, Mat& src)
{
    src = imread(fileName);
    if (src.empty())
    {
        return 1;
    }
    return 0;
}

int processFrame(const Mat& src, Mat& dst)
{
    const int kSize = 11;
    medianBlur(src, dst, kSize);
    return 0;
}

int show(const std::string &caption, const Mat& src, const Mat& dst)
{
    if (src.rows != dst.rows || src.cols != dst.cols)
    {
        return 1;
    }
    
    Mat display(src.rows, src.cols + dst.cols, src.type());
    Mat srcRoi = display(Rect(0, 0, src.cols, src.rows));
    src.copyTo(srcRoi);
    Mat dstRoi = display(Rect(src.cols, 0, dst.cols, dst.rows));
    dst.copyTo(dstRoi);

    namedWindow(caption);
    imshow(caption, display);
    waitKey();

    return 0;
}