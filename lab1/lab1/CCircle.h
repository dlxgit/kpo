#pragma once
#include "IShape.h"
#define _USE_MATH_DEFINES 
#include <math.h>

class CCircle : public IShape
{
public:
	CCircle(Point & point, long long radius);

	Point GetCenter() const;
	long long GetRadius() const;

	std::string ToString() const override;
	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	void Accept(IShapeVisitor & visitor) override;

private:
	Point m_center;
	long long m_radius;
};