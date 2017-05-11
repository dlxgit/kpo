#pragma once
#include <memory>
#include "IShape.h"
#include "CircleFactory.h"
#include "TriangleFactory.h"
#include "RectangleFactory.h"


class CShapeFactory
{
public:
	static std::unique_ptr<IShape> CreateShape(const std::vector<std::string> & inputParts);
};