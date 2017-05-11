#include "FileParser.h"
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include "ShapeFactory.h"

std::vector<std::unique_ptr<IShape>> CFileParser::ReadShapes()
{
	std::vector<std::unique_ptr<IShape>> result;
	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open())
	{
		throw std::ios_base::failure("Error: inputFile is not found");
	}
	std::cout << "Loading shapes from file..." << std::endl;

	std::string command;
	while (std::getline(inputFile, command))
	{
		std::vector<std::string> commandParts;
		boost::split(commandParts, command, boost::is_any_of(" "));
		result.emplace_back(CShapeFactory::CreateShape(commandParts));
	}

	return result;
}