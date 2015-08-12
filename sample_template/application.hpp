#pragma once

#include <string>
#include <opencv2/core/core.hpp>

#include "processing.hpp"

class Application
{
 public:
    struct Parameters
    {
        std::string imgFileName;
    };
    int parseArguments(int argc, const char **argv, Parameters &params);

    int getFrame(const std::string &fileName, cv::Mat& src);
    int processFrame(const cv::Mat& src, cv::Mat& dst);
    int show(const std::string &caption, const cv::Mat& src, const cv::Mat& dst);
 private:
    Processing processor;
};
