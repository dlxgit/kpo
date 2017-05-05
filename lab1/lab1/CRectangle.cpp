#include "CRectangle.h"

CRectangle::CRectangle(const Point & position, double width, double height)
{
	m_position = position;
	m_width = width;
	m_height = height;
}

CRectangle::CRectangle(const std::vector<std::string> & inputParts)
{
	double x = std::stod(inputParts[1]);
	double y = std::stod(inputParts[2]);
	double width = std::stod(inputParts[3]);
	double height = std::stod(inputParts[4]);

	if (width <= 0 || height <= 0)
	{
		throw std::invalid_argument("Error: width and height of rectangle must be positive");
	}
	*this = CRectangle(Point(x, y), width, height);
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

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
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
