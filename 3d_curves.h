#pragma once

#include <iosfwd>

struct Vector3D {
	double x;
	double y;
	double z;
};

std::ostream& operator<<(std::ostream& os, const Vector3D& vec);

class Curve3D {
protected:
	const char* m_type;

public:
	const char* type() const { return m_type; };
	virtual double radius() const = 0;
	virtual double step() const = 0;
	virtual Vector3D getPoint(double t) const = 0;
	virtual Vector3D getDerivative(double t) const = 0;

};

class Circle : public Curve3D {
private:
	double m_radius;

public:
	Circle(double radius) : m_radius(radius) { m_type = "Circle"; };
	double radius() const override;
	double step() const override;
	Vector3D getPoint(double t) const override;
	Vector3D getDerivative(double t) const override;

};

class Ellipse : public Curve3D {
private:
	double m_radiusX;
	double m_radiusY;

public:
	Ellipse(double radiusX, double radiusY) : m_radiusX(radiusX), m_radiusY(radiusY) { m_type = "Ellipse"; };
	double radius() const override;
	double step() const override;
	Vector3D getPoint(double t) const override;
	Vector3D getDerivative(double t) const override;

};

class Helix : public Curve3D {
private:
	double m_radius;
	double m_step;

public:
	Helix(double radius, double step) : m_radius(radius), m_step(step) { m_type = "Helix"; };
	double radius() const override;
	double step() const override;
	Vector3D getPoint(double t) const override;
	Vector3D getDerivative(double t) const override;

};