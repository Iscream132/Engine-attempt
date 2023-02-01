#include "object.h"

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

void Circle::solution(Circle it, Circle that)
{
	Vector v1, v2;
	v1 = it.m_velocity;
	v2 = that.m_velocity;
	double m1 = it.m_mess, m2 = that.m_mess;
	it.m_velocity = ((m1 - m2) * v1 + 2 * m2 * v2) *(1/ (m1 + m2));
	that.m_velocity = ((m2 - m1) * v2 + 2 * m1 * v1) * (1 / (m1 + m2));
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




