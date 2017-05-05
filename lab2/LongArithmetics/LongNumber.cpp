#include "stdafx.h"
#include "LongNumber.h"
#include <algorithm>

std::vector<int> CLongNumber::GetData() const
{
	return m_data;
}

CLongNumber CLongNumber::operator+(const CLongNumber & right) const
{
	int length;

	auto a = m_data;
	int size_a = a.size();
	std::reverse(a.begin(), a.end());

	auto b = right.GetData();
	int size_b = b.size();
	std::reverse(b.begin(), b.end());

	std::vector<int> result;

	int index = 0;
	int rest = 0;


// 	int foo = 1;
// 	while (true)
// 	{
// 		int bar = foo;
// 		int foo = 3;
// 	}

	for (; index < size_a || index < size_b; ++index)
	{
		int firstOperand = index >= size_a ? 0 : a[index];
		int secondOperand = index >= size_b ? 0 : b[index];

		int resValue = firstOperand + secondOperand + rest;
		rest = (resValue > 9) ? resValue - 9 : 0;
		result.push_back(resValue % 10);
	}



	std::reverse(result.begin(), result.end());

	return CLongNumber(result);
}

CLongNumber CLongNumber::operator-(const CLongNumber & right) const
{
	int length;

	auto a = m_data;
	int size_a = a.size();
	std::reverse(a.begin(), a.end());

	auto b = right.GetData();
	int size_b = b.size();
	std::reverse(b.begin(), b.end());

	std::vector<int> result;

	int index = 0;
	int rest = 0;


	// 	int foo = 1;
	// 	while (true)
	// 	{
	// 		int bar = foo;
	// 		int foo = 3;
	// 	}

	for (; index < size_a || index < size_b; ++index)
	{
		int firstOperand = index >= size_a ? 0 : a[index];
		int secondOperand = index >= size_b ? 0 : b[index];

		int resValue = firstOperand - secondOperand - rest;
		if (resValue < 0)
		{
			rest = resValue < 0 ? 1 : rest;
			resValue = 10 - abs(resValue);
		}
		else
		{
			rest = 0;
		}

		result.push_back(resValue);
	}

	if (rest != 0)
	{
		result.push_back(rest);
	}
	
	while (result.begin() + 1 != result.end() && result.back() == 0)
	{
		result.erase(result.end() - 1);
	}

	std::reverse(result.begin(), result.end());

	return CLongNumber(result);
}

CLongNumber CLongNumber::operator*(const CLongNumber & right) const
{
	int length;

	auto a = m_data;
	int size_a = a.size();
	std::reverse(a.begin(), a.end());

	auto b = right.GetData();
	int size_b = b.size();
	std::reverse(b.begin(), b.end());


	int zero_count_a = 0;
	while (m_data[zero_count_a] == 0) 
	{
		++zero_count_a;
	};

	int zero_count_b = 0;
	while (m_data[zero_count_b] == 0)
	{
		++zero_count_b;
	};
	
	if (zero_count_a == a.size() || zero_count_b == b.size())
	{
		return CLongNumber("0");
	}

	std::vector<int> result;
	int index = 0;
	int rest = 0;
	for (int i1 = zero_count_a; i1 < size_a; ++i1)
	{
		for (int i2 = zero_count_b; i2 < size_b; ++i2)
		{
			
		}
	}

	// 	int foo = 1;
	// 	while (true)
	// 	{
	// 		int bar = foo;
	// 		int foo = 3;
	// 	}

	for (; index < size_a || index < size_b; ++index)
	{
		int firstOperand = index >= size_a ? 0 : a[index];
		int secondOperand = index >= size_b ? 0 : b[index];

		int resValue = firstOperand + secondOperand + rest;
		rest = (resValue > 9) ? resValue - 9 : 0;
		result.push_back(resValue % 10);
	}

	if (rest != 0)
	{
		result.push_back(rest);
	}

	std::reverse(result.begin(), result.end());


	return CLongNumber(result);
}

CLongNumber CLongNumber::operator/(const CLongNumber & right) const
{
	return CLongNumber(std::vector<int>(1));
}

bool CLongNumber::operator==(const CLongNumber & right) const
{
	if (m_data.size() != right.m_data.size())
	{
		return false;
	}

	for (size_t i = 0; i < m_data.size(); ++i)
	{
		if (m_data[i] != right.m_data[i])
		{
			return false;
		}
	}

	return true;
}

std::ostream & operator<<(std::ostream & os, const CLongNumber & longNumber)
{
	auto data = longNumber.GetData();
	for (int el : data)
	{
		os << el;
	}
	return os;
}