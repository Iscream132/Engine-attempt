#include "object.h"

#define imgsize 1000

extern Mat container;
extern Mat dst;


Mat test1 = imread("test1.png");
Mat test2 = imread("test2.png");
Mat test3 = imread("test3.png");


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
	
	//m_location = m_location_last + 0.0625 * m_velocity + 0.5 * 0.0625 * 0.0625 * m_acceleration位置更新代码
	if (((it.m_location + 0.0625 * it.m_velocity + 0.5 * 0.0625 * 0.0625 * it.m_acceleration)
		- (that.m_location + 0.0625 * that.m_velocity + 0.5 * 0.0625 * 0.0625 * that.m_acceleration)).vector_module()
		<= (it.m_radius + that.m_radius))//预判下一帧是否碰撞
	{
		return 1;
	}
	else return 0;
}



void Circle::crash_solution(Circle& it, Circle& that)
{
	if (this->crash_detection(it, that) == 1)
	{
		Vector v1, v2;
		v1 = it.m_velocity;
		v2 = that.m_velocity;
		double m1 = it.m_mess, m2 = that.m_mess;
		it.m_velocity.change_velocity(v1, v2, m1, m2);
		that.m_velocity.change_velocity(v2, v1, m2, m1);
	}
}

int Circle::edge_detection()//2代表撞到边缘，0代表未碰撞
{
	if ((this->m_location.x() + this->m_radius) >= imgsize-30 || (this->m_location.x() - this->m_radius) <= 20 ||
		(this->m_location.y() + this->m_radius) >= imgsize-100 || (this->m_location.y() - this->m_radius) <= 20)
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
	if (this->edge_detection() == 2)
	{
		if ((this->m_location.x() + this->m_radius) >= imgsize - 30 || (this->m_location.x() - this->m_radius) <= 30)
		{
			this->m_velocity.anti_x();
		}
		else if ((this->m_location.y() + this->m_radius) >= imgsize - 100 || (this->m_location.y() - this->m_radius) <= 30)
		{
			this->m_velocity.anti_y();
		}
	}
}

void Circle::update()
{
	m_location = m_location_last + 0.0625 * m_velocity + 0.5*0.0625 * 0.0625 * m_acceleration;//0.0625是每帧间的时间间隔
	Vector inter = m_location;
	m_velocity = m_velocity + 0.0625 * m_acceleration;
	m_location_last = inter;
}

void Circle::gravity()
{
	Vector gravity(0, -9.8);
	m_acceleration = m_acceleration - gravity;
}

void Circle::add_circle()
{
	Mat roi;
	roi = container(Rect(this->location_x() - this->m_radius, this->location_y() - this->m_radius, 2*this->m_radius, 2*this->m_radius));
	addWeighted(roi, 0.5, this->m_src, 0.5, 0.0, roi);
}

void Circle::run()
{
	this->add_circle();
	this->edge_solution();
	this->update();
}

int main()//演示程序
{
	//一个球类构造函数 Circle(Mat src, double mess, Vector location, Vector location_last, Vector velocity, Vector acceleration)
	Circle o(test1, 0, Vector(100, 100), Vector(100, 100), Vector(50, 10), Vector(0, 0));//mess为根据图片尺寸自动生成
	o.gravity();
	Circle v(test2, 0, Vector(200, 400), Vector(200, 400), Vector(-50, -10), Vector(0, 0));
	v.gravity();
	Circle q(test3, 0, Vector(300, 700), Vector(300, 700), Vector(30, 10), Vector(0, 0));
	q.gravity();
	Circle inter;
	display engine;
	namedWindow("Engine");
	for (int j = 0; j < 1500; j++)
	{
		std::cout << j << std::endl;
		inter.crash_solution(o, v);
		inter.crash_solution(o, q);
		inter.crash_solution(q, v);
		o.run();
		v.run();
		q.run();
		engine.show();
	}
	return 0;
}

