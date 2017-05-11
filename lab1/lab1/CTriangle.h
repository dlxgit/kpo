#pragma once
#include "IShape.h"
#include <array>
#include "CLineSegment.h"


class CTriangle : public IShape
{
public:
	CTriangle(const Point & firstPoint, const Point & secondPoint, const Point & thirdPoint);

	std::array<Point, 3> GetPoints() const;
	std::string ToString() const override;
	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

private:
	Point m_firstPoint;
	Point m_secondPoint;
	Point m_thirdPoint;
};