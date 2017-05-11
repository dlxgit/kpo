#pragma once
#include <string>
#include <vector>
#include <memory>
#include "IShape.h"

class CShapeConverter
{
public:
	static void SaveToFile(const std::vector<std::unique_ptr<IShape>> & data, const std::string & fileName = "output.txt");
};