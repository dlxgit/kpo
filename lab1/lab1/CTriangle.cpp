#include "CTriangle.h"
#include "CLineSegment.h"

CTriangle::CTriangle(const Point & firstPoint, const Point & secondPoint, const Point & thirdPoint)
{
	m_firstPoint = firstPoint;
	m_secondPoint = secondPoint;
	m_thirdPoint = thirdPoint;
}

CTriangle::CTriangle(const std::vector<std::string> & inputParts)
{
	Point p1 = Point(std::stod(inputParts[1]), std::stod(inputParts[2]));
	Point p2 = Point(std::stod(inputParts[3]), std::stod(inputParts[4]));
	Point p3 = Point(std::stod(inputParts[5]), std::stod(inputParts[6]));
	*this = CTriangle(p1, p2, p3);
}

std::string CTriangle::ToString() const
{
	std::pair<double, double> point1 = m_firstPoint;
	std::pair<double, double> point2 = m_secondPoint;
	std::pair<double, double> point3 = m_thirdPoint;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) <<
		"triangle <" <<
		point1.first << ", " <<
		point1.second << ">, " << "<" <<
		point2.first << ", " <<
		point2.second << ">, <" <<
		point3.first << ", " <<
		point3.second << ">, S = " <<
		GetArea() << ", P = " <<
		GetPerimeter();
	return ss.str();
}

double CTriangle::GetArea() const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - CLineSegment(m_firstPoint, m_secondPoint).GetLength()) * (p - CLineSegment(m_secondPoint, m_thirdPoint).GetLength()) * (p - CLineSegment(m_firstPoint, m_thirdPoint).GetLength()));
}

double CTriangle::GetPerimeter() const
{
	return CLineSegment(m_firstPoint, m_secondPoint).GetLength() + CLineSegment(m_secondPoint, m_thirdPoint).GetLength() + CLineSegment(m_firstPoint, m_thirdPoint).GetLength();
}

std::array<Point, 3> CTriangle::GetPoints() const
{
	return{ m_firstPoint, m_secondPoint, m_thirdPoint };
}