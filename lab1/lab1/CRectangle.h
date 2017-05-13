#pragma once
#include "IShape.h"

class CRectangle : public IShape
{
public:
	CRectangle(const Point & position, long long width, long long height);

	Point GetPosition() const;
	long long GetWidth() const;
	long long GetHeight() const;

	std::string ToString() const override;
	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	void Accept(IShapeVisitor & visitor) override;
private:
	Point m_position;
	long long m_width;
	long long m_height;
};