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
	int crash_detection(Circle it, Circle that);//碰撞检测函数
	int edge_detection();//边缘检测函数
	double location_x();//返回位置的横坐标
	double location_y();//返回位置的纵坐标
	void crash_solution(Circle& it, Circle& that);//碰撞处理方法
	void edge_solution();//边缘碰撞处理方法
	void update();//位置更新函数
	void gravity();//重力环境函数
	void add_circle();//球体添加函数
	void run();//运行函数
};

