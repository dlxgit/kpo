#include "stdafx.h"
#include "LongNumberExpression.h"

CLongNumberExpression::CLongNumberExpression(const std::string & str)
{
	std::vector<std::string> commandParts;
	std::string newString;
	for (auto el : str)
	{
		newString += CStringUtils::PutSeparatorsIfNeeded(boost::lexical_cast<std::string>(el));
	}

	boost::split(commandParts, newString, boost::is_any_of(" "));

	for (size_t i = 0; i < commandParts.size(); )
	{
		if (commandParts[i].compare(" ") == 0 || commandParts[i].compare("") == 0)
		{
			commandParts.erase(commandParts.begin() + i);
		}
		else
		{
			++i;
		}
	}

	Validate(commandParts);

	*this = CLongNumberExpression(CLongNumber(commandParts[0]), CLongNumber(commandParts[2]), commandParts[1][0]);
}

CLongNumberExpression::CLongNumberExpression(const CLongNumber & left, const CLongNumber & right, char operationSymbol)
	:
	left(left),
	right(right),
	operationSymbol(operationSymbol)
{

}

CLongNumber CLongNumberExpression::CalculateResult() const
{
	CLongNumber exprResult;
	switch (operationSymbol)
	{
	case '+':
		exprResult = left + right;
		break;
	case '-':
		exprResult = left - right;
		break;
	case '*':
		exprResult = left * right;
		break;
	case '/':
		exprResult = left / right;
		break;
	}
	return exprResult;
};

std::string CLongNumberExpression::ToString() const
{
	return left.ToString() + operationSymbol + right.ToString();
}

bool CLongNumberExpression::Validate(const std::vector<std::string> & expr)
{
	if (expr.size() != 3 || expr[1].length() != 1)
	{
		throw std::invalid_argument("bad expression input");
	}

	if (!CStringUtils::IsSeparator(expr[1][0]))
	{
		throw std::invalid_argument("bad expression input");
	}
}