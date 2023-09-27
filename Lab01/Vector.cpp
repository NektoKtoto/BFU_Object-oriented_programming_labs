#include "Vector.h"
#include "Point.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Vector::Vector()
	:x(0), y(0), z(0) {}

Vector::Vector(float x, float y, float z)
	:x(x), y(y), z(z) {}

Vector::Vector(const Point& start, const Point& end)
{
	x = end.getX() - start.getX();
	y = end.getY() - start.getY();
	z = end.getZ() - start.getZ();
}

float Vector::getX() const
{
	return x;
}

float Vector::getY() const
{
	return y;
}

float Vector::getZ() const
{
	return z;
}

void Vector::print() const
{
	std::cout << std::fixed << std::setprecision(2) << "{" << x << ", " << y << ", " << z << "}";
}

Vector& Vector::operator=(const Vector& vector)
{
	x = vector.getX();
	y = vector.getY();
	z = vector.getZ();
	return *this;
}

//сумма с вектором
Vector Vector::operator+(const Vector& vector) const
{
	return Vector(x + vector.getX(), y + vector.getY(), z + vector.getZ());
}

//разность с вектором
Vector Vector::operator-(const Vector& vector) const
{
	return Vector(x - vector.getX(), y - vector.getY(), z - vector.getZ());
}

//получение обратного вектора
Vector Vector::revers() const
{
	return Vector(x * (-1), y * (-1), z * (-1));
}

//получение единичного вектора
Vector Vector::single() const
{
	return Vector(x / lenght(), y / lenght(), z / lenght());
}

//получение длины вектора
float Vector::lenght() const
{
	return sqrt(x * x + y * y + z * z);
}

//скалярное произведение с вектором
float Vector::scalarMultiplication(const Vector& vector) const
{
	return x * vector.getX() + y * vector.getY() + z * vector.getZ();
}

//векторное произведение с вектором
Vector Vector::vectorMultiplication(const Vector& vector) const
{
	float newX = y * vector.getZ() - z * vector.getY();
	float newY = z * vector.getX() - x * vector.getZ();
	float newZ = x * vector.getY() - y * vector.getX();
	return Vector(newX, newY, newZ);
}

//смешанное произведение с векторами
float Vector::mixedMultiplication(const Vector& vector1, const Vector& vector2) const
{
	return scalarMultiplication(vector1.vectorMultiplication(vector2));
}

//проверка на коллинеарность с вектором
bool Vector::collinear(const Vector& vector) const
{
	Vector result = vectorMultiplication(vector);
	return (result.getX() == 0) && (result.getY() == 0) && (result.getZ() == 0);
}

//проверка на компланарность с векторами
bool Vector::coplanar(const Vector& vector1, const Vector& vector2) const
{
	return (mixedMultiplication(vector1, vector2) == 0);
}
