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
	long long x = std::stoll(inputParts[1]);
	long long y = std::stoll(inputParts[2]);
	long long width = std::stoll(inputParts[3]);
	long long height = std::stoll(inputParts[4]);

	if (width <= 0 || height <= 0)
	{
		throw std::invalid_argument("Error: width and height of rectangle must be positive");
	}
	return std::make_unique<CRectangle>(Point(x, y), width, height);
}