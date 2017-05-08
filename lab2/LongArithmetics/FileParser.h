#pragma once
#include "LongNumber.h"
#include <vector>
#include <fstream>
#include <string>
#include "LongNumber.h"

class CFileParser
{
	std::vector<CLongNumber> ReadShapes()
	{
		std::vector<CLongNumber> result;

		std::ifstream inputFile("input.txt");

		if (!inputFile.is_open())
		{
			throw std::ios_base::failure("Error: inputFile is not found");
		}
		std::cout << "Loading shapes from file..." << std::endl;

		std::string command;
		while (std::getline(inputFile, command))
		{
			std::vector<std::string> commandParts;
			boost::split(commandParts, command, boost::is_any_of(" +-*/"));

			
			std::for_each(commandParts.begin(), commandParts.end(), [](const std::string & str)
			{
				
			});

			result.emplace_back(new CLongNumber());
		}

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

	static std::string Calculate();

}