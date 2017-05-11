#pragma once
#include "IShape.h"

class CRectangle : public IShape
{
public:
	CRectangle(const Point & position, double width, double height);

	Point GetPosition() const;
	double GetWidth() const;
	double GetHeight() const;

	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
private:
	Point m_position;
	double m_width;
	double m_height;
};