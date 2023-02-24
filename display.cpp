#include "display.h"

Mat container = imread("container.png");//背景贴图
Mat dst = imread("container.png");//中间变量
Mat test1 = imread("test1.png");//测试样例
Mat test2 = imread("test2.png");
Mat test3 = imread("test3.png");

display::display()
{
}

void display::show()
{
	imshow("Engine", container);
	waitKey(3);//设置运行速度
	dst.copyTo(container);
}