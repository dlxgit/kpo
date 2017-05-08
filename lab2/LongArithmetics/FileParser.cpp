#include "FileParser.h"


CFileParser::CFileParser(const std::string & fileName)
	:fileName(fileName)
{

}

std::vector<std::string> CFileParser::ReadLines()
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
}


std::vector<int> CFileParser::StringToNumberVec(const std::string & str)
{
	std::vector<int> result;
	for (auto el : str)
	{
		result.push_back(boost::lexical_cast<int>(el));
	}
	return result;
}