#pragma once
#include "IShape.h"
#include "ShapeVisitor.h"

class CVisitableShape : public IShape
{
public:
	CVisitableShape() = default;
	virtual CLongNumber GetArea() const = 0;
	virtual CLongNumber GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual void Accept(IShapeVisitor & visitor) = 0;
};