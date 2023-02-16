#include "display.h"

Mat container = imread("container.png");
Mat dst = imread("container.png");
Mat object = imread("test.png");

display::display()
{
}

void display::show()
{
	imshow("Engine", container);
	waitKey(3);
	dst.copyTo(container);
}


