#pragma once
#include <iostream>

class Vector
{
private:
	double m_x;
	double m_y;
public:
	Vector();
	Vector(double x, double y);
	~Vector();
	void show();
	double x();//���غ�������
	double y();
	void anti_x();//ȡ������
	void anti_y();
	void change_velocity(Vector v1, Vector v2, double m1, double m2);//Ϊ�˸ı�������˽��������д���ٶȸı亯��
	double vector_module();
	void operator=(const Vector& it);//�����ĸ�ֵ���������
	Vector operator+(const Vector& it) const;//�����ļӼ����������
	Vector operator-(const Vector& it) const;
	double operator*(const Vector& it) const;//�������
	Vector operator*(const int& it) const;//�����ļ�������
	Vector operator*(const double& it) const;
	Vector operator*(const long double& it) const;
	friend Vector operator*(const double it, const Vector& that);
};
