#pragma once
#include "StringUtils.h"


std::string CStringUtils::PutSeparatorsIfNeeded(const std::string & str, const std::string & separator)
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

bool CStringUtils::IsSeparator(char c)
{
	std::set<char> expected_delimeters = { '+','-','*','/' };
	return expected_delimeters.find(c) != expected_delimeters.end();
}