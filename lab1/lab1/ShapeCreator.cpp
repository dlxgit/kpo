#include "ShapeCreator.h"

std::unique_ptr<IShape> AddNewShape(const std::vector<std::string> & inputParts)
{
	if (inputParts.size() == 7 && inputParts[0].compare(std::string("triangle")) == 0)
	{
		return std::make_unique<CTriangle>(inputParts);
	}
	else if (inputParts.size() == 5 && inputParts[0].compare(std::string("rectangle")) == 0)
	{
		return std::make_unique<CRectangle>(inputParts);
	}
	else if (inputParts.size() == 4 && inputParts[0].compare(std::string("circle")) == 0 && std::stod(inputParts[3]) >= 0)
	{
		return std::make_unique<CCircle>(inputParts);
	}
	else
	{
		throw std::invalid_argument("Incorrect command");
	}
}

std::vector<std::unique_ptr<IShape>> ReadShapes()
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
		result.emplace_back((AddNewShape(commandParts)));
	}

	return result;
}

void OutputResult(const std::vector<std::unique_ptr<IShape>> & shapes)
{
	std::ofstream outputFile("output.txt");

	for (size_t i = 0; i < shapes.size(); ++i)
	{
		outputFile << shapes[i]->ToString() << " P=" << shapes[i]->GetPerimeter() << " S=" << shapes[i]->GetArea() << std::endl;
	}
}