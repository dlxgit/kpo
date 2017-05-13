#pragma once
#include "VisitableShape.h"

class CRectangle : public CVisitableShape
{
public:
	CRectangle(const Point & position, double width, double height);

	Point GetPosition() const;
	double GetWidth() const;
	double GetHeight() const;

	std::string ToString() const override;
	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	void Accept(IShapeVisitor & visitor) override;
private:
	Point m_position;
	double m_width;
	double m_height;
};