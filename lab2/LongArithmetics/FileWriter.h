#pragma once
#include "LongNumberExpression.h"
#include <fstream>

class CFileWriter
{
public:
	CFileWriter(const std::string & fileName = "output.txt")
	{
		this->outputFile = std::ofstream(fileName);
	}

	~CFileWriter()
	{
		outputFile.flush();
	}
	
	void Write(const CLongNumberExpression & expr)
	{
		outputFile << expr.ToString() << '=' << expr.CalculateResult() << std::endl;
	}

	void Write(const std::string & text)
	{
		outputFile << text << std::endl;
	}
	
private:
	std::ofstream outputFile;
};