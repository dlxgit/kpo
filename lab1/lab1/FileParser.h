#pragma once
#include <memory>
#include <vector>
#include "IShape.h"
#include <fstream>

class CFileParser
{
public:
	static std::vector<std::unique_ptr<IShape>> ReadShapes();
};