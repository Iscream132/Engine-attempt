#pragma once
#include "Engine.h"
#include "display.h"


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
	Circle():Rigidbody() { m_radius = 0; m_acceleration = Vector(0, 0); };
	Circle(double mess, Vector location, Vector location_last, Vector velocity, double radius, Vector acceleration)
		:Rigidbody(mess, location, location_last, velocity) {m_radius = radius; m_acceleration = acceleration;};
	int crash_detection(Circle it, Circle that);
	int edge_detection();
	double location_x();
	double location_y();
	void crash_solution(Circle& it, Circle& that);
	void edge_solution();
	void update();
	void gravity();
	void add_circle();
	void run();//ÔËÐÐº¯Êý
};

