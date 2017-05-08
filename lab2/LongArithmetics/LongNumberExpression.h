#pragma once
#include "LongNumber.h"
#include <string>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <set>
#include "StringUtils.h"

class CLongNumberExpression
{
public:

	CLongNumberExpression(const std::string & str)
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

		CLongNumberExpression(CLongNumber(commandParts[0]), CLongNumber(commandParts[2]), commandParts[1][0]);
	};

	CLongNumberExpression(const CLongNumber & left, const CLongNumber & right, char operationSymbol)
		:
		left(left), 
		right(right), 
		operationSymbol(operationSymbol)
	{

	};

	CLongNumber CalculateResult() const
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
	};

	std::string ToString() const
	{
		std::string result = left.ToString() + ' ' + operationSymbol + ' ' + '=' + right.ToString();
	};

	static std::string CalculateResultString(const CLongNumber & leftOperand, const CLongNumber & rightOperand, char operationSymbol)
	{
		CLongNumber exprResult;
		switch (operationSymbol)
		{
		case '+':
			exprResult = leftOperand + rightOperand;
			break;
		case '-':
			exprResult = leftOperand - rightOperand;
			break;
		case '*':
			exprResult = leftOperand * rightOperand;
			break;
		case '/':
			exprResult = leftOperand / rightOperand;
			break;
		default:
			throw std::invalid_argument("unexpected operation symbol <" + operationSymbol + '>');
		}
		std::string result = leftOperand.ToString() + ' ' + operationSymbol + ' ' + '=' + exprResult.ToString();
	};


private:

	bool Validate(const std::vector<std::string> & expr)
	{
		if (expr.size() != 3 || expr[1].length() != 1)
		{
			throw std::invalid_argument("bad expression input");
		}

		if (!CStringUtils::IsSeparator(expr[1][0]))
		{
			throw std::invalid_argument("bad expression input");
		}
	};

	CLongNumber left;
	CLongNumber right;
	char operationSymbol;
};