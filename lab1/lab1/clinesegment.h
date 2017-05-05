#pragma once

#include "IShape.h"

class CLineSegment
{
public:
	CLineSegment(const Point & first, const Point & second);

	std::pair<Point, Point> GetPoints() const;
	double GetLength() const;

private:
	Point m_firstPoint;
	Point m_secondPoint;
};