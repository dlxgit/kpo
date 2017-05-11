#pragma once
#include "CCircle.h"
#include <memory>

class CCircleFactory
{
public:
	std::unique_ptr<IShape> CreateShape(const std::vector<std::string> & inputParts) const;
	static CCircleFactory * GetInstance();

private:
	CCircleFactory();
	~CCircleFactory();
private:
	static CCircleFactory * m_instance;
};