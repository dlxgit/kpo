#pragma once
#include <string>
#include <boost/lexical_cast.hpp>
#include <iomanip>
#include <vector>
#include "LongNumber.h"

typedef std::pair<int, int> Point;

class IShape
{
public:
	IShape() = default;
	CLongNumber virtual GetArea() const = 0;
	CLongNumber virtual GetPerimeter() const = 0;
	std::string virtual ToString() const = 0;
};