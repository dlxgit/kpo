#include "CCircle.h"


CCircle::CCircle(Point & point, const double radius)
{
	m_center = point;
	m_radius = radius;
}

CCircle::CCircle(const std::vector<std::string> & inputParts)
{
	Point pos = Point(std::stod(inputParts[1]), std::stod(inputParts[2]));
	double radius = std::stod(inputParts[3]);
	*this = CCircle(pos, radius);
}


std::string CCircle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << "circle <" <<
		m_center.first << ", " <<
		m_center.second << ">, R = " <<
		GetRadius() << ", S = " <<
		GetArea() << ", P = " <<
		GetPerimeter();
	return ss.str();
}

double CCircle::GetArea() const
{
	return M_PI * GetRadius() * GetRadius();
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * GetRadius();
}

Point CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
