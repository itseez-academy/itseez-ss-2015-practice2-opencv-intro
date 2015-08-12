#include "application.hpp"
#include "processing.hpp"

#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int Application::parseArguments(int argc, const char **argv, Application::Parameters &params)
{
    if (argc < 2)
    {
        return 1;
    }
    params.imgFileName = std::string(argv[1]);
    return 0;
}

int Application::getFrame(const std::string &fileName, Mat& src)
{
    src = imread(fileName);
    if (src.empty())
    {
        return 1;
    }
    return 0;
}

int Application::processFrame(const Mat& src, Mat& dst)
{
    processor.processFrame(src, dst);

    if (dst.empty())
    {
        return 1;
    }

    return 0;
}

int Application::show(const std::string &caption, const Mat& src, const Mat& dst)
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
    char key = waitKey(1);

    return key;
}
