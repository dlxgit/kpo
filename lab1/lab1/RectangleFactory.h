#pragma once
#include "CRectangle.h"
#include <memory>

class CRectangleFactory
{
public:
	std::unique_ptr<IShape> CreateShape(const std::vector<std::string> & inputParts) const;
	static CRectangleFactory * GetInstance();

private:
	CRectangleFactory();
	~CRectangleFactory();
	
private:
	static CRectangleFactory * m_instance;
};