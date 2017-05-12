#pragma once
#include "ShapeVisitor.h"

class CShapePrinter: public CShapeVisitor
{
public:
	void Visit(IShape & shape) const override;
};