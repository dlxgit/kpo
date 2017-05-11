#include "ShapeFactory.h"
#include "CTriangle.h"

std::unique_ptr<IShape> CShapeFactory::CreateShape(const std::vector<std::string> & inputParts)
{
	if (inputParts.size() == 7 && inputParts[0].compare(std::string("triangle")) == 0)
	{
		return CTriangleFactory::GetInstance()->CreateShape(inputParts);
		//return std::make_unique<CTriangle>(inputParts);
	}
	else if (inputParts.size() == 5 && inputParts[0].compare(std::string("rectangle")) == 0)
	{
		return CRectangleFactory::GetInstance()->CreateShape(inputParts);
		//return std::make_unique<CRectangle>(inputParts);
	}
	else if (inputParts.size() == 4 && inputParts[0].compare(std::string("circle")) == 0 && std::stod(inputParts[3]) >= 0)
	{
		return CCircleFactory::GetInstance()->CreateShape(inputParts);
		//return std::make_unique<CCircle>(inputParts);
	}
	else
	{
		throw std::invalid_argument("Incorrect command");
	}
}