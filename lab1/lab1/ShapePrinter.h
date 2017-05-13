#pragma once
#include "ShapeVisitor.h"


class CShapePrinter: public IShapeVisitor
{
public:
	void Visit(CRectangle & shape) override;
	void Visit(CTriangle & shape) override;
	void Visit(CCircle & shape) override;
};