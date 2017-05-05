#pragma once
#include "IShape.h"
#include <array>
#include "CLineSegment.h"

class CTriangle : public IShape
{
public:
	CTriangle(const Point & firstPoint, const Point & secondPoint, const Point & thirdPoint);
	CTriangle(const std::vector<std::string> & inputParts);

	std::array<Point, 3> GetPoints() const;
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;

private:
	Point m_firstPoint;
	Point m_secondPoint;
	Point m_thirdPoint;
};