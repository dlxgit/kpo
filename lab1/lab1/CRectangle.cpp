#include "CRectangle.h"

CRectangle::CRectangle(const Point & position, double width, double height)
{
	m_position = position;
	m_width = width;
	m_height = height;
}

std::string CRectangle::ToString() const
{
	std::stringstream ss;
	std::pair<double, double> position = m_position;
	ss << std::fixed << std::setprecision(2) << "rectangle <" <<
		position.first << ", " <<
		position.second << "> " << "width = " <<
		m_width << ", height = " <<
		m_height << ", S = " <<
		GetArea() << ", P = " <<
		GetPerimeter();
	return ss.str();
}

CLongNumber CRectangle::GetArea() const
{
	return CLongNumber(boost::lexical_cast<std::string>(m_width)) * CLongNumber(boost::lexical_cast<std::string>(m_height));
}

CLongNumber CRectangle::GetPerimeter() const
{
	return CLongNumber(boost::lexical_cast<std::string>(m_width + m_height)) * CLongNumber("2");
}

Point CRectangle::GetPosition() const
{
	return m_position;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

void CVisitableShape::Accept(IShapeVisitor & visitor)
{
	//visitor.Visit(*this);
}