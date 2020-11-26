#include <iostream>
#include <opencv2/opencv.hpp>
#include "matrix2d.h"
#include "image.h"

int main()
{
	const auto src = cv::imread("D:/OneDrive - Rinne's Space/Pictures/Avatar.jpg");
	
	my::image img(src);
	img.show("234");
	
	/*imshow("Figure1", src);
	src.copyTo()
	cv::waitKey(0);*/

}