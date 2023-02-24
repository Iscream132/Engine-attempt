#include "object.h"

#define imgsize 1000
#define pi 3.1415926535

extern Mat container;//������ͼ
extern Mat dst;//�м����
extern Mat test1;//������ͼ
extern Mat test2;
extern Mat test3;

Rigidbody::Rigidbody()
{
	m_mess = 0;
	Vector m_location(0, 0);
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

Circle::Circle(Mat src, double mess, Vector location, Vector location_last, Vector velocity, Vector acceleration)
	:Rigidbody(mess, location, location_last, velocity)
{
	m_src = src;
	m_mess = (1.0 / 6.0) * pi * src.rows * src.rows * src.rows * 1.0;//�����ܶ�Ĭ��Ϊ1
	m_radius = src.rows / 2.0;
	m_acceleration = acceleration;
	this->gravity();//��������ʱĬ�ϸ�����������
}

int Circle::crash_detection(Circle it, Circle that)//1������ײ��0����δ��ײ
{
	//m_location = m_location_last + 0.0625 * m_velocity + 0.5 * 0.0625 * 0.0625 * m_accelerationλ�ø��´���
	if (((it.m_location + 0.0625 * it.m_velocity + 0.5 * 0.0625 * 0.0625 * it.m_acceleration)
		- (that.m_location + 0.0625 * that.m_velocity + 0.5 * 0.0625 * 0.0625 * that.m_acceleration)).vector_module()
		<= (it.m_radius + that.m_radius))//Ԥ����һ֡�Ƿ���ײ
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

int Circle::edge_detection()//2����ײ����Ե��0����δ��ײ
{
	if (((this->m_location + 0.0625 * this->m_velocity + 0.5 * 0.0625 * 0.0625 * this->m_acceleration).x() + this->m_radius) >= imgsize - 10.0
		|| ((this->m_location + 0.0625 * this->m_velocity + 0.5 * 0.0625 * 0.0625 * this->m_acceleration).x() - this->m_radius) <= 10.0)
	{
		return 1;
	}
	if (((this->m_location + 0.0625 * this->m_velocity + 0.5 * 0.0625 * 0.0625 * this->m_acceleration).y() + this->m_radius) >= imgsize - 100.0
		|| ((this->m_location + 0.0625 * this->m_velocity + 0.5 * 0.0625 * 0.0625 * this->m_acceleration).y() - this->m_radius) <= 10.0)//дһЩ������ֹ����,Ԥ����һ֡�Ƿ����
	{
		return 2;
	}
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
	if (this->edge_detection() == 1)
	{
		this->m_velocity.anti_x();
	}
	if (this->edge_detection() == 2)
	{
		this->m_velocity.anti_y();
	}
}

void Circle::update()
{
	m_location = m_location_last + 0.0625 * m_velocity + 0.5 * 0.0625 * 0.0625 * m_acceleration;//0.0625��ÿ֡���ʱ����
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
	roi = container(Rect(this->location_x() - this->m_radius, this->location_y() - this->m_radius, 2 * this->m_radius, 2 * this->m_radius));
	addWeighted(roi, 0.5, this->m_src, 0.5, 0.0, roi);
}

void Circle::run()//�������еĺ���
{
	this->add_circle();
	this->edge_solution();
	this->update();
}

int main()//��ʾ����
{
	//һ�����๹�캯�� Circle(Mat src, double mess, Vector location, Vector location_last, Vector velocity, Vector acceleration);
	Circle o(test1, 0, Vector(800, 100), Vector(800, 100), Vector(-60, 50), Vector(0, 0));//messΪ����ͼƬ�ߴ��Զ����ɣ��˴�����ٶ���Ӱ��
	Circle v(test2, 0, Vector(700, 600), Vector(700, 600), Vector(-60, -60), Vector(0, 0));
	Circle q(test3, 0, Vector(300, 700), Vector(300, 700), Vector(70, -60), Vector(0, 0));
	Circle inter;//������ײ��⺯��������
	display engine;//��ʾ�������
	namedWindow("Engine");//������ʾ����
	for (int j = 0; j < 3500; j++)//��������ʱ��
	{
		std::cout << j << std::endl;
		inter.crash_solution(o, v);//��ʱ���ֶ���ÿ������������ײ������֪����ô����
		inter.crash_solution(o, q);
		inter.crash_solution(q, v);
		o.run();//�������к���
		v.run();
		q.run();
		engine.show();//��ʾͼ��
	}
	return 0;
}