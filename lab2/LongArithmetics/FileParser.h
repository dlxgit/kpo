#pragma once
#include "LongNumber.h"
#include <vector>
#include <fstream>
#include <string>
#include "LongNumber.h"

class CFileParser
{
public:

	CFileParser(const std::string & fileName = "input.txt")
		:fileName(fileName)
	{

	}

	static std::vector<std::string> ReadLines()
	{
		std::cout << "Loading expressions from file..." << std::endl;
		std::vector<std::string> result;

		std::ifstream inputFile("input.txt");
		if (!inputFile.is_open())
		{
			throw std::ios_base::failure("Error: inputFile is not found");
		}

		std::string command;
		while (std::getline(inputFile, command))
		{			
			result.push_back(command);
		}
		std::cout << "Loading has successfully finished" << std::endl;
		return result;
	};

private:
	static std::vector<int> StringToNumberVec(const std::string & str)
	{
		std::vector<int> result;
		for (auto el : str)
		{
			result.push_back(boost::lexical_cast<int>(el));
		}
	};

	std::string fileName;
};