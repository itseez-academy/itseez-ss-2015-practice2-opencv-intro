#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int getFrame(Mat& src);

int processFrame(const Mat& src, Mat& dst);

int show(const Mat& src, const Mat& dst);
