#pragma once

#include <string>

struct Parameters
{
    std::string imgFileName;
};

int parseArguments(int argc, const char **argv, Parameters &params);