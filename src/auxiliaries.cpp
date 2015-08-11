#include "auxiliaries.hpp"

int parseArguments(int argc, char **argv, std::string &fileName)
{
    if (argc < 2)
    {
        return 1;
    }
    fileName = std::string(argv[1]);
    return 0;
}