#pragma once

#include <string>

struct Parameters
{
    std::string imgFileName;
};

int parseArguments(int argc, char **argv, Parameters &params);