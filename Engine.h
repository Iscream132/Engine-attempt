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
	double x();//返回横纵坐标
	double y();
	void anti_x();//取反函数
	void anti_y();
	void change_velocity(Vector v1, Vector v2, double m1, double m2);//为了改变向量的私有数据所写的速度改变函数
	double vector_module();
	void operator=(const Vector& it);//向量的赋值运算符重载
	Vector operator+(const Vector& it) const;//向量的加减运算符重载
	Vector operator-(const Vector& it) const;
	double operator*(const Vector& it) const;//向量点乘
	Vector operator*(const int& it) const;//向量的几种数乘
	Vector operator*(const double& it) const;
	Vector operator*(const long double& it) const;
	friend Vector operator*(const double it, const Vector& that);
};
