#include "Engine.h"

Vector::Vector()
{
	m_x = 0;
	m_y = 0;
}

Vector::Vector(double x, double y)
{
	m_x = x;
	m_y = y;
}

Vector::~Vector()
{}

void Vector::show()
{
	std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
}

Vector Vector::operator+(const Vector& it) const
{
	Vector Vect_Sum;
	Vect_Sum.m_x = m_x + it.m_x;
	Vect_Sum.m_y = m_y + it.m_y;
	return Vect_Sum;
}

Vector Vector::operator-(const Vector& it) const
{
	Vector Vect_Sub;
	Vect_Sub.m_x = m_x - it.m_x;
	Vect_Sub.m_y = m_y - it.m_y;
	return Vect_Sub;
}

void Vector::operator=(const Vector& it)
{
	m_x = it.m_x;
	m_y = it.m_y;
}

double Vector::operator*(const Vector& it) const
{
	double Vect_Mul = 0.0;
	Vect_Mul = m_x * it.m_x + m_y * it.m_y;
	return Vect_Mul;
}

Vector Vector::operator*(const int& it) const
{
	Vector Vect_Mul;
	Vect_Mul.m_x = m_x * it;
	Vect_Mul.m_y = m_y * it;
	return Vect_Mul;
}

Vector Vector::operator*(const double& it) const
{
	Vector Vect_Mul;
	Vect_Mul.m_x = m_x * it;
	Vect_Mul.m_y = m_y * it;
	return Vect_Mul;
}

Vector Vector::operator*(const long double& it) const
{
	Vector Vect_Mul;
	Vect_Mul.m_x = m_x * it;
	Vect_Mul.m_y = m_y * it;
	return Vect_Mul;
}

Vector operator*(const int it, const Vector& that)
{
	return that * it;
}


int main()
{
	Vector a(1, 2), b(3, 4);
	(a + b).show();
	(a - b).show();
	std::cout << (a * b) << std::endl;
	(2 * a).show();
	(a * 2).show();
	return 0;
}
