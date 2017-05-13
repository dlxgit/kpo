#pragma once
#include "IShape.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

class IShapeVisitor
{
public:
	virtual void Visit(CTriangle & shape) = 0;
	virtual void Visit(CRectangle & shape) = 0;
	virtual void Visit(CCircle & shape) = 0;
};