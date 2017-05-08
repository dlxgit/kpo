#pragma once
#include <string>

class CStringUtils
{
public:
	
	static std::string PutSeparatorsIfNeeded(const std::string & str, const std::string & separator = " ")
	{
		std::string result;
		if (str.length() == 1 && IsSeparator(str[0]))
		{
			result = separator + str + separator;
		}
		else
		{
			result = str;
		}
		return result;
	}

	static bool IsSeparator(char c)
	{
		std::set<char> expected_delimeters = { '+','-','*','/' };
		return expected_delimeters.find(c) != expected_delimeters.end();
	}
};