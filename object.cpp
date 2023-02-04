#include "object.h"

#define objsize 52
#define imgsize 1100

Mat container = imread("container.png");
Mat dst = imread("container.png");
Mat object = imread("test.png");


Rigidbody::Rigidbody()
{
	m_mess = 0;
	Vector m_location(0,0);
	Vector m_location_last(0, 0);
	Vector m_velocity(0, 0);
}

Rigidbody::Rigidbody(double mess, Vector location, Vector location_last, Vector velocity)
{
	m_mess = mess;
	m_location = location;
	m_location_last = location_last;
	m_velocity = velocity;
}

Rigidbody::~Rigidbody()
{
}

int Circle::crash_detection(Circle it, Circle that)//1代表碰撞，0代表未碰撞
{
	
	if (((it.m_location - that.m_location).vector_module()) <= (it.m_radius + that.m_radius))
		return 1;
	else return 0;
}

int Circle::edge_detection(Circle it)//2代表撞到边缘，0代表为碰撞
{
	if ((it.m_velocity.x() + it.m_radius) > imgsize || (it.m_velocity.x() - it.m_radius) < 0 || (it.m_velocity.y() + it.m_radius) > imgsize || (it.m_velocity.y() - it.m_radius) < 0)
		return 2;
	else return 0;
}



void Circle::crush_solution(Circle it, Circle that)
{
	Vector v1, v2;
	v1 = it.m_velocity;
	v2 = that.m_velocity;
	double m1 = it.m_mess, m2 = that.m_mess;
	it.m_velocity = ((m1 - m2) * v1 + 2 * m2 * v2) *(1/ (m1 + m2));
	that.m_velocity = ((m2 - m1) * v2 + 2 * m1 * v1) * (1 / (m1 + m2));
}

void Circle::edge_solution(Circle it)
{
	if ((it.m_velocity.x() + it.m_radius) > imgsize || (it.m_velocity.x() - it.m_radius) < 0)
		it.m_velocity.anti_x();
	else if((it.m_velocity.y() + it.m_radius) > imgsize || (it.m_velocity.y() - it.m_radius) < 0)
		it.m_velocity.anti_y();
}

void Circle::update()
{
	Vector inter = m_location;
	m_location = m_location_last + m_velocity * 1;
	m_location_last = inter;
}

void Circle::gravity()
{
	Vector gravity(0, -9.8);
	m_acceleration = m_acceleration - gravity;
}

void Circle::add_circle(double x, double y, int radius)
{
	int a = (int)x, b = (int)y;
	Mat roi;
	roi = container(Rect(a - radius, b + radius, objsize, objsize));
	addWeighted(roi, 0.5, object, 0.5, 0.0, roi);
	imshow("Engine", container);
	waitKey(0);
	dst.copyTo(container);
}

int main()
{
	Circle o(0, Vector(0, 0), Vector(0, 0), Vector(0, 0), 0, Vector(0, 0));
	Mat img = imread("test.png");
	std::cout << img.rows << " " << img.cols << std::endl;
	int a = (int)100, b = (int)100;
	namedWindow("Engine");
	for (; a < 1000 && b < 1000; a = a + 20, b = b + 20)
	{
		o.add_circle(a, b, 5);
	}
	return 0;
}

