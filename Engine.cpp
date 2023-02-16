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
{
}

void Vector::show()
{
	std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
}

double Vector::x()
{
	return m_x;
}

double Vector::y()
{
	return m_y;
}

void Vector::anti_x()
{
	m_x = -m_x;
}

void Vector::anti_y()
{
	m_y = -m_y;
}

void Vector::change_velocity(Vector v1, Vector v2, double m1, double m2)
{
	this->m_x = ((m1 - m2) * v1.m_x + 2 * m2 * v2.m_x) * (1 / (m1 + m2));
	this->m_y = ((m1 - m2) * v1.m_y + 2 * m2 * v2.m_y) * (1 / (m1 + m2));
}

double Vector::vector_module()
{
	double square_sum = 0.0;
	square_sum = m_x * m_x + m_y * m_y;
	return sqrt(square_sum);
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

Vector operator*(const double it, const Vector& that)
{
	return that * it;
}




	
