#pragma once
#include <string>
#include <set>

class CStringUtils
{
public:
	static std::string PutSeparatorsIfNeeded(const std::string & str, const std::string & separator = " ");
	static bool IsSeparator(char c);
};