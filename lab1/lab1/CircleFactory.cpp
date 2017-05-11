#include "CircleFactory.h"


CCircleFactory * CCircleFactory::m_instance;
CCircleFactory::CCircleFactory() {};

CCircleFactory::~CCircleFactory()
{
	delete(m_instance);
}

CCircleFactory * CCircleFactory::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CCircleFactory();
	}
	return m_instance;
}

std::unique_ptr<IShape> CCircleFactory::CreateShape(const std::vector<std::string> & inputParts) const
{
	Point pos = Point(std::stod(inputParts[1]), std::stod(inputParts[2]));
	double radius = std::stod(inputParts[3]);
	return std::make_unique<CCircle>(pos, radius);
}