#include "display.h"

Mat container = imread("container.png");//������ͼ
Mat dst = imread("container.png");//�м����
Mat test1 = imread("test1.png");//��������
Mat test2 = imread("test2.png");
Mat test3 = imread("test3.png");

display::display()
{
}

void display::show()
{
	imshow("Engine", container);
	waitKey(3);//���������ٶ�
	dst.copyTo(container);
}