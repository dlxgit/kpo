#include "CCircle.h"


CCircle::CCircle(Point & point, long long radius)
{
	m_center = point;
	m_radius = radius;
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

CLongNumber CCircle::GetArea() const
{
	return CLongNumber("22") * CLongNumber(boost::lexical_cast<std::string>(m_radius * m_radius)) / CLongNumber("7");
}

CLongNumber CCircle::GetPerimeter() const
{
	return CLongNumber("44") * CLongNumber(boost::lexical_cast<std::string>(m_radius)) / CLongNumber("7");
}

Point CCircle::GetCenter() const
{
	return m_center;
}

long long CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::Accept(IShapeVisitor & visitor)
{
	visitor.Visit(*this);
}