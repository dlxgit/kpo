#pragma once

#include "IShape.h"

class CLineSegment
{
public:
	CLineSegment(const Point & first, const Point & second);

	std::pair<Point, Point> GetPoints() const;
	long long  GetLength() const;

private:
	Point m_firstPoint;
	Point m_secondPoint;
};