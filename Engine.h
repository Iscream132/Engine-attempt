#pragma once
# include<iostream> 
# include<opencv2/opencv.hpp> 

using namespace cv;

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
	void operator=(const Vector& it);//向量的赋值运算符重载
	Vector operator+(const Vector& it) const;//向量的加减运算符重载
	Vector operator-(const Vector& it) const;
	double operator*(const Vector& it) const;//向量点乘
	Vector operator*(const int& it) const;//向量的几种数乘
	Vector operator*(const double& it) const;
	Vector operator*(const long double& it) const;
	friend Vector operator*(const int it, const Vector& that);
};

