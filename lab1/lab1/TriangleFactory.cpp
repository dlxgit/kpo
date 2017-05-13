#include "TriangleFactory.h"



CTriangleFactory * CTriangleFactory::m_instance;

CTriangleFactory::CTriangleFactory() {};

CTriangleFactory::~CTriangleFactory()
{
	delete(m_instance);
}

CTriangleFactory * CTriangleFactory::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CTriangleFactory();
	}
	return m_instance;
}

std::unique_ptr<IShape> CTriangleFactory::CreateShape(const std::vector<std::string> & inputParts) const
{
	Point p1 = Point(std::stoll(inputParts[1]), std::stoll(inputParts[2]));
	Point p2 = Point(std::stoll(inputParts[3]), std::stoll(inputParts[4]));
	Point p3 = Point(std::stoll(inputParts[5]), std::stoll(inputParts[6]));
	return std::make_unique<CTriangle>(p1, p2, p3);
}