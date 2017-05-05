#include "CLineSegment.h"
#include <math.h>


CLineSegment::CLineSegment(const Point & first, const Point & second)
{
	m_firstPoint = first;
	m_secondPoint = second;
}

std::pair<Point, Point> CLineSegment::GetPoints() const
{
	return std::make_pair(m_firstPoint, m_secondPoint);
}

double CLineSegment::GetLength() const
{
	auto firstPointPos = GetPoints().first;
	auto secondPointPos = GetPoints().second;
	return sqrt(pow(firstPointPos.first - secondPointPos.first, 2) + pow(firstPointPos.second - secondPointPos.second, 2));
}