#pragma once
#include "IShape.h"

class CShapeVisitor
{
public:
	virtual void Visit(IShape & shape) const = 0;
};