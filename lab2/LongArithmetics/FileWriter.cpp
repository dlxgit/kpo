#include "FileWriter.h"

CFileWriter::CFileWriter(const std::string & fileName)
{
	this->outputFile = std::ofstream(fileName);
}

CFileWriter::~CFileWriter()
{
	outputFile.flush();
}

void CFileWriter::Write(const CLongNumberExpression & expr)
{
	outputFile << expr.ToString() << '=' << expr.CalculateResult() << std::endl;
}

void CFileWriter::Write(const std::string & text)
{
	outputFile << text << std::endl;
}