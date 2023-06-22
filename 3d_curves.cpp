#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

#include "3d_curves.h"

std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
{
	os << "[x : " << vec.x << ", y : " << vec.y << ", z : " << vec.z << "]";
	return os;
}

double Circle::radius() const
{
	return m_radius;
}

double Circle::step() const
{
	return 0;
}

Vector3D Circle::getPoint(double t) const
{
	return Vector3D{m_radius * std::cos(t), m_radius * std::sin(t), 0};
}

Vector3D Circle::getDerivative(double t) const
{
	return Vector3D{ -m_radius * std::sin(t), m_radius * std::cos(t), 0 };
}

double Ellipse::radius() const
{
	return (m_radiusX + m_radiusY) / 2;
}

double Ellipse::step() const
{
	return 0;
}

Vector3D Ellipse::getPoint(double t) const
{
	return Vector3D{ m_radiusX * std::cos(t), m_radiusY * std::sin(t), 0 };
}

Vector3D Ellipse::getDerivative(double t) const
{
	return Vector3D{ -m_radiusX * std::sin(t), m_radiusY * std::cos(t), 0 };
}

double Helix::radius() const
{
	return m_radius;
}

double Helix::step() const
{
	return m_step;
}

Vector3D Helix::getPoint(double t) const
{
	return Vector3D{ m_radius * std::cos(t), m_radius * std::sin(t), m_step * t / (2.0 * M_PI) };
}

Vector3D Helix::getDerivative(double t) const
{
	return Vector3D{ -m_radius * std::sin(t), m_radius * std::cos(t), m_step * t / (2.0 * M_PI) };
}
