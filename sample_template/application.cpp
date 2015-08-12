#include "application.hpp"

int parseArguments(int argc, const char **argv, Parameters &params)
{
    if (argc < 2)
    {
        return 1;
    }
    params.imgFileName = std::string(argv[1]);
    return 0;
}