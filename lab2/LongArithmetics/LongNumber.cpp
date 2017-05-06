#include "stdafx.h"
#include "LongNumber.h"
#include <algorithm>
#include <sstream>

std::vector<int> CLongNumber::GetData() const
{
	return m_data;
}

CLongNumber CLongNumber::operator+(const CLongNumber & right) const
{
	auto a = m_data;
	int size_a = a.size();
	std::reverse(a.begin(), a.end());

	auto b = right.GetData();
	int size_b = b.size();
	std::reverse(b.begin(), b.end());

	//std::vector<int> result(std::max(size_a, size_b) + 1);
	std::vector<int> result;

	int index = 0;
	int rest = 0;

	//result.erase(result.begin(), result.begin() + a.size() - 1);
	result.insert(result.begin(), a.begin(), a.end());

	for (; index < size_b; ++index)
	{
		AddNumber(result, index, b[index]);
	}

	std::reverse(result.begin(), result.end());

	return CLongNumber(result);
}

CLongNumber CLongNumber::operator-(const CLongNumber & right) const
{
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

	
	while (result.begin() + 1 != result.end() && result.back() == 0)
	{
		result.erase(result.end() - 1);
	}

	std::reverse(result.begin(), result.end());

	return CLongNumber(result);
}

CLongNumber CLongNumber::operator*(const CLongNumber & right) const
{
	auto a = m_data;
	int size_a = a.size();
	std::reverse(a.begin(), a.end());

	auto b = right.GetData();
	int size_b = b.size();
	std::reverse(b.begin(), b.end());


	int zero_count_a = 0;
	for (; zero_count_a < size_a && a[zero_count_a] == 0; ++zero_count_a){};

	int zero_count_b = 0;
	for (; zero_count_b < size_b && b[zero_count_b] == 0; ++zero_count_b){};
	
	if (zero_count_a == a.size() || zero_count_b == b.size())
	{
		return CLongNumber("0");
	}

	std::vector<int> result;
	//std::vector<int> result(size_a * size_b);
	for (size_t i = 0; i < size_a * size_b; ++i)
	{
		result.push_back(0);
	}
// 	for (auto & el : result)
// 	{
// 		el = 0;
// 	}

	int index = 0;
	int rest = 0;
	for (int i1 = zero_count_a; i1 < size_a; ++i1)
	{
		for (int i2 = zero_count_b; i2 < size_b; ++i2)
		{
			int res = a[i1] * b[i2] + rest;
			AddNumber(result, i1 + i2, res);
		}
	}

	// 	int foo = 1;
	// 	while (true)
	// 	{
	// 		int bar = foo;
	// 		int foo = 3;
	// 	}

// 	for (size_t i = 0; i < zero_count_a * zero_count_b; ++i)
// 	{
// 		result.insert(result.begin(), 0);
// 	}

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

CLongNumber CLongNumber::operator/(const CLongNumber & right) const
{
	auto a = m_data;
	int size_a = a.size();
	//std::reverse(a.begin(), a.end());

	auto b = right.GetData();
	int size_b = b.size();
	//std::reverse(b.begin(), b.end());


	
	if (right == CLongNumber("0"))
	{
		throw(std::invalid_argument("division by zero"));
	}
	else if (*this== CLongNumber("0"))
	{
		return CLongNumber("0");
	}
	else if (*this < right)
	{
		return CLongNumber("0");
	}
	else if (*this == right)
	{
		return CLongNumber("1");
	}

	int i = 0;
	std::vector<int> result;

	CLongNumber temp(*this);
	CLongNumber rest("0");

	while (true)
	{
		if (i > size_a - size_b)
		{
			return CLongNumber(result);
		}

		std::vector<int> current;

		current.insert(current.begin(), temp.m_data.begin() + i, temp.m_data.begin() + i + size_b);
		if (rest.m_data[0] == 0)
		{

		}
		else
		{
			current.erase(current.begin(), current.begin() + rest.m_data.size());

			current.insert(current.begin(), rest.m_data.begin(), rest.m_data.end());
			current = (CLongNumber(current) + rest).m_data;
		}

		bool checked = false;
		for (size_t i = 0; i < 11; ++i)
		{
			std::string nStr = boost::lexical_cast<std::string>(i);
			
			if (right * CLongNumber(nStr) > CLongNumber(current))
			{
				checked = true;
				result.push_back(i - 1);
				rest = temp - CLongNumber(boost::lexical_cast<std::string>(i - 1)) * right;
				rest.erase(rest.begin() + right.m_data.size(), rest.end());
				break;
			}
			
		}

		if (!checked)
		{
			//err?
		}
	}
	
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