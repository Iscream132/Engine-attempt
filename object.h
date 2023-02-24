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
	Mat m_src;//�������ͼ
	double m_radius;
	Vector m_acceleration;
public:
	Circle() :Rigidbody() { m_radius = 0; m_acceleration = Vector(0, 0); };
	Circle(Mat src, double mess, Vector location, Vector location_last, Vector velocity, Vector acceleration);
	int crash_detection(Circle it, Circle that);//��ײ��⺯��
	int edge_detection();//��Ե��⺯��
	double location_x();//����λ�õĺ�����
	double location_y();//����λ�õ�������
	void crash_solution(Circle& it, Circle& that);//��ײ������
	void edge_solution();//��Ե��ײ������
	void update();//λ�ø��º���
	void gravity();//�������ٶȻ�������
	void add_circle();//������Ӻ���
	void run();//���к���
};
