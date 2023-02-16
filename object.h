#pragma once
#include "Engine.h"


class Rigidbody
{
protected:
	double m_mess;
	Vector m_location;
	Vector m_location_last;
	Vector m_velocity;
public:
	Rigidbody();
	Rigidbody(double mess, Vector location, Vector location_last, Vector velocity);
	~Rigidbody();
};


class Circle :public Rigidbody
{
private:
	double m_radius;
	Vector m_acceleration;
public:
	Circle(double mess, Vector location, Vector location_last, Vector velocity, double radius, Vector acceleration)
		:Rigidbody(mess, location, location_last, velocity) {m_radius = radius; m_acceleration = acceleration;};
	int crash_detection(Circle it, Circle that);
	int edge_detection();
	double location_x();
	double location_y();
	void crush_solution(Circle it, Circle that);
	void edge_solution();
	void update();
	void gravity();
	void add_circle(double x, double y, int radius);
};

