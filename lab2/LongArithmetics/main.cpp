#include "LongNumber.h"
#include <iostream>
#include "LongNumberExpression.h"
#include "FileParser.h"
#include "FileWriter.h"


int main()
{
	std::vector<std::string> strings;
	try
	{
		strings = CFileParser().ReadLines();
	}
	catch (const std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	CFileWriter fileWriter;

	for (auto el : strings)
	{
		try
		{
			fileWriter.Write(CLongNumberExpression(el));
		}
		catch (const std::invalid_argument & ia)
		{
			fileWriter.Write("bad_result");
		}
	}

	return 0;
}