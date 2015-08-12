#include <opencv2/core/core.hpp>
#include <iostream>

#include "auxiliaries.hpp"
#include "img_proc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    const std::string caption = "Median filter";
    Parameters params;
	if (parseArguments(argc, argv, params) != 0)
    {
        cout << "practice2 <img_name>" << endl;
        cout << "<img_name> - image name for filtering" << endl;
        return 1;
    }

    Mat src, dst;
    
    if (getFrame(params.imgFileName, src) != 0)
    {
        cout << "Error: \'src\' image is null or empty!" << endl;
        return 2;
    }
    
    if (processFrame(src, dst) != 0)
    {
        cout << "Error: Filtering failed!" << endl;
        return 3;
    }
    
    show(caption, src, dst);

	return 0;
}
