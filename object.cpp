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

void display()
{
	imshow("Engine", container);
	waitKey(5);
	dst.copyTo(container);
}

int Circle::crash_detection(Circle it, Circle that)//1������ײ��0����δ��ײ
{
	
	if (((it.m_location - that.m_location).vector_module()) <= (it.m_radius + that.m_radius))
		return 1;
	else return 0;
}



void Circle::crash_solution(Circle& it, Circle& that)
{
	Vector v1, v2;
	v1 = it.m_velocity;
	v2 = that.m_velocity;
	double m1 = it.m_mess, m2 = that.m_mess;
	it.m_velocity.change_velocity(v1, v2, m1, m2);
	that.m_velocity.change_velocity(v2, v1, m2, m1);
}

int Circle::edge_detection()//2����ײ����Ե��0����δ��ײ
{
	if ((this->m_location.x() + this->m_radius) >= imgsize-30 || (this->m_location.x() - this->m_radius) <= 0 ||
		(this->m_location.y() + this->m_radius) >= imgsize-150 || (this->m_location.y() - this->m_radius) <= 0)
		return 2;
	else return 0;
}

double Circle::location_x()
{
	return m_location.x();
}

double Circle::location_y()
{
	return m_location.y();
}


void Circle::edge_solution()
{
	if ((this->m_location.x() + this->m_radius) >= imgsize-30 || (this->m_location.x() - this->m_radius) <= 0)
	{
		this->m_velocity.anti_x();
	}
	else if ((this->m_location.y() + this->m_radius) >= imgsize-150 || (this->m_location.y() - this->m_radius) <= 0)
	{
		this->m_velocity.anti_y();
	}
}

void Circle::update()
{
	m_location = m_location_last + 0.0625 * m_velocity + 0.5*0.0625 * 0.0625 * m_acceleration;//0.0625��ÿ֡���ʱ����
	Vector inter = m_location;
	m_velocity = m_velocity + 0.0625 * m_acceleration;
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
	roi = container(Rect(a - radius, b - radius, objsize, objsize));
	addWeighted(roi, 0.5, object, 0.5, 0.0, roi);
}

int main()
{
	//Circle(double mess, Vector location, Vector location_last, Vector velocity, double radius, Vector acceleration)
	Circle o(10, Vector(100, 100), Vector(100, 100), Vector(50, 0), objsize/2, Vector(0, 0));
	o.gravity();
	Circle v(100, Vector(200, 100), Vector(200, 100), Vector(-30, 0), objsize / 2, Vector(0, 0));
	v.gravity();
	Mat img = imread("test.png");
	std::cout << img.rows << " " << img.cols << std::endl;
	namedWindow("Engine");
	for (int j = 0; j < 1500; j++)
	{
		std::cout << j << std::endl;
		o.add_circle(o.location_x(), o.location_y(), 5);
		v.add_circle(v.location_x(), v.location_y(), 5);
		display();
		if (o.edge_detection() == 2)
		{
			o.edge_solution();
		}
		if (v.edge_detection() == 2)
		{
			v.edge_solution();
		}
		if (o.crash_detection(o, v) == 1)
		{
			o.crash_solution(o, v);
		}
		o.update();
		v.update();
	}
	return 0;
}

