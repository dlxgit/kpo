#pragma once
#include <string>
#include <boost/lexical_cast.hpp>
#include <iomanip>
#include <vector>
#include "LongNumber.h"


typedef std::pair<int, int> Point;

class CTriangle;
class CRectangle;
class CCircle;

class IShapeVisitor
{
public:
	virtual void Visit(CTriangle & shape) = 0;
	virtual void Visit(CRectangle & shape) = 0;
	virtual void Visit(CCircle & shape) = 0;
};

class CShapePrinter : public IShapeVisitor
{
public:
	void Visit(CRectangle & shape) override;
	void Visit(CTriangle & shape) override;
	void Visit(CCircle & shape) override;
};

class Element
{
public:
	virtual void Accept(IShapeVisitor & visitor) = 0;
};

class IShape : public Element
{
public:
	IShape() = default;
	CLongNumber virtual GetArea() const = 0;
	CLongNumber virtual GetPerimeter() const = 0;
	std::string virtual ToString() const = 0;
};