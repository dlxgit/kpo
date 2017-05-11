#pragma once
#include "IShape.h"
#define _USE_MATH_DEFINES 
#include <math.h>

class CCircle : public IShape
{
public:
	CCircle(Point & point, double radius);

	Point GetCenter() const;
	double GetRadius() const;

	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;

private:
	Point m_center;
	double m_radius;
};