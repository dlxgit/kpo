#pragma once
#include "LongNumber.h"
#include <string>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <set>
#include "StringUtils.h"

class CLongNumberExpression
{
public:

	CLongNumberExpression(const std::string & str);

	CLongNumberExpression(const CLongNumber & left, const CLongNumber & right, char operationSymbol);

	CLongNumber CalculateResult() const;

	std::string ToString() const;

private:

	bool Validate(const std::vector<std::string> & expr);

	CLongNumber left;
	CLongNumber right;
	char operationSymbol;
};