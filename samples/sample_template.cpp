#include <opencv2/core/core.hpp>
#include <iostream>

#include "auxiliaries.hpp"
#include "img_proc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	if (parseArguments(argc, argv) != 0)
    {
        cout << "Incorrect input parameters!" << endl;
        return 1;
    }

    Mat src, dst;
    
    if (getFrame(src) != 0)
    {
        cout << "Error: \'src\' image is null or empty!" << endl;
        return 2;
    }
    
    processFrame(src, dst);
    
    show(src, dst);

	return 0;
}
