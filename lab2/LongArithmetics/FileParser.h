#pragma once
#include "LongNumber.h"
#include <vector>
#include <fstream>
#include <string>
#include "LongNumber.h"

class CFileParser
{
public:
	CFileParser(const std::string & fileName = "input.txt");
	static std::vector<std::string> ReadLines();

private:
	static std::vector<int> StringToNumberVec(const std::string & str);
	std::string fileName;
};