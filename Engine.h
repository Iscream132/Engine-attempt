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
	void operator=(const Vector& it);//�����ĸ�ֵ���������
	Vector operator+(const Vector& it) const;//�����ļӼ����������
	Vector operator-(const Vector& it) const;
	double operator*(const Vector& it) const;//�������
	Vector operator*(const int& it) const;//�����ļ�������
	Vector operator*(const double& it) const;
	Vector operator*(const long double& it) const;
	friend Vector operator*(const int it, const Vector& that);
};

