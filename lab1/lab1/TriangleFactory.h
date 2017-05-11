#pragma once
#include "CTriangle.h"
#include <memory>

class CTriangleFactory
{
public:
	std::unique_ptr<IShape> CreateShape(const std::vector<std::string> & inputParts) const;
	static CTriangleFactory * GetInstance();

private:
	CTriangleFactory();
	~CTriangleFactory();
private:
	static CTriangleFactory * m_instance;
};