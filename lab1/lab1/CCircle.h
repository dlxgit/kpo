#pragma once
#include "VisitableShape.h"
#define _USE_MATH_DEFINES 
#include <math.h>

class CCircle : public CVisitableShape
{
public:
	CCircle(Point & point, double radius);

	Point GetCenter() const;
	double GetRadius() const;

	std::string ToString() const override;
	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	void Accept(IShapeVisitor & visitor) override;

private:
	Point m_center;
	double m_radius;
};