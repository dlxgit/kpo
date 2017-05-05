#pragma once
#include <string>
#include <boost/lexical_cast.hpp>
#include <iomanip>
#include <vector>

typedef std::pair<int, int> Point;

class IShape
{
public:
	IShape() = default;
	double virtual GetArea() const = 0;
	double virtual GetPerimeter() const = 0;
	std::string virtual ToString() const = 0;
};