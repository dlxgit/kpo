#include "RectangleFactory.h"

CRectangleFactory * CRectangleFactory::m_instance;
CRectangleFactory::CRectangleFactory() {};

CRectangleFactory::~CRectangleFactory()
{
	delete(m_instance);
}

CRectangleFactory * CRectangleFactory::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CRectangleFactory();
	}
	return m_instance;
}

std::unique_ptr<IShape> CRectangleFactory::CreateShape(const std::vector<std::string> & inputParts) const
{
	double x = std::stod(inputParts[1]);
	double y = std::stod(inputParts[2]);
	double width = std::stod(inputParts[3]);
	double height = std::stod(inputParts[4]);

	if (width <= 0 || height <= 0)
	{
		throw std::invalid_argument("Error: width and height of rectangle must be positive");
	}
	return std::make_unique<CRectangle>(Point(x, y), width, height);
}