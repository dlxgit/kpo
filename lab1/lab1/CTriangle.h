#pragma once
#include "IShape.h"
#include "VisitableShape.h"
#include <array>
#include "CLineSegment.h"


class CTriangle : public CVisitableShape
{
public:
	CTriangle(const Point & firstPoint, const Point & secondPoint, const Point & thirdPoint);

	std::array<Point, 3> GetPoints() const;
	std::string ToString() const override;
	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	void Accept(IShapeVisitor & visitor) override;

private:
	Point m_firstPoint;
	Point m_secondPoint;
	Point m_thirdPoint;
};