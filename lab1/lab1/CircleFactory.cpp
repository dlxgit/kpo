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
	Point pos = Point(std::stol(inputParts[1]), std::stol(inputParts[2]));
	long long radius = std::stol(inputParts[3]);
	return std::make_unique<CCircle>(pos, radius);
}