#pragma once
#include "LongNumberExpression.h"
#include <fstream>

class CFileWriter
{
public:
	CFileWriter(const std::string & fileName = "output.txt");
	~CFileWriter();
	
	void Write(const CLongNumberExpression & expr);
	void Write(const std::string & text);
	
private:
	std::ofstream outputFile;
};