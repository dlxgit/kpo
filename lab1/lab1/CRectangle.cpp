#include "CRectangle.h"

CRectangle::CRectangle(const Point & position, long long width, long long height)
{
	m_position = position;
	m_width = width;
	m_height = height;
}

std::string CRectangle::ToString() const
{
	std::stringstream ss;
	std::pair<long long, long long> position = m_position;
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

long long CRectangle::GetWidth() const
{
	return m_width;
}

long long CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::Accept(IShapeVisitor & visitor)
{
	visitor.Visit(*this);
}