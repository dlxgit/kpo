#include "LongNumber.h"
#include <algorithm>
#include <sstream>

CLongNumber::CLongNumber(const std::string & data)
{
	if (data.length() == 1 && data[0] == '0')
	{
		m_data.push_back(0);
		return;
	}

	bool begin = true;
	for (size_t i = 0; i < data.length(); ++i)
	{

		if (data[i] == '.' || data[i] == ',')
		{
			return;
		}
		if (data[i] == '-')
		{
			std::string newVec;
			newVec.insert(newVec.begin(), data.begin() + 1, data.end());
			*this = CLongNumber(newVec);
			return;
		}
		if (!isdigit(data[i]))
		{
			throw std::invalid_argument("incorrent symbol");
		}

		if (begin && data[i] == '0')
		{
			if (i == data.size() - 1)
			{
				m_data.push_back(boost::lexical_cast<int>(data[i]));
			}
		}
		else
		{
			begin = false;
			m_data.push_back(boost::lexical_cast<int>(data[i]));
		}
	}

};

CLongNumber::CLongNumber(const CLongNumber & other)
	:m_data(other.m_data)
{

};

CLongNumber::CLongNumber(const std::vector<int> & data)
	:m_data(data)
{

};

std::vector<int> CLongNumber::GetData() const
{
	return m_data;
}

std::string CLongNumber::ToString() const
{
	std::string res;
	for (auto el : m_data)
	{
		res += boost::lexical_cast<std::string>(el);
	}
	return res;
}

CLongNumber CLongNumber::operator+(const CLongNumber & right) const
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
	if (*this < right)
	{
		return right - *this;
	}

	auto a = m_data;
	int size_a = a.size();
	std::reverse(a.begin(), a.end());

	auto b = right.GetData();
	int size_b = b.size();
	std::reverse(b.begin(), b.end());

	std::vector<int> result;

	int index = 0;
	int rest = 0;

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

	for (size_t i = 0; i < size_a * size_b; ++i)
	{
		result.push_back(0);
	}

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

	auto b = right.GetData();
	int size_b = b.size();
	
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

	int current_div_length = size_b;
	while (true)
	{
		if (temp.m_data.size() < size_b)
		{
			if (!temp.m_data.empty())
			{
				result.push_back(0);
			}
			break;
		}

		CLongNumber firstN = CLongNumber(getFirstNVec(temp.m_data, current_div_length));

		if (firstN < b)
		{
			++current_div_length;
			if (!result.empty())
			{
				result.push_back(0);
			}
			if (temp == firstN)
			{
				break;
			}
			continue;
		}
		else
		{
			temp.m_data.erase(temp.m_data.begin(), temp.m_data.begin() + firstN.m_data.size());
			current_div_length = size_b;
		}

		CLongNumber temp_sub = CLongNumber(right);
		bool isFound = false;
		for (int i = 1; i < 11; ++i)
		{
			if (temp_sub + right > firstN || temp_sub == firstN)
			{
				result.push_back(i);
				isFound = true;
				break;
			}
			else
			{
				temp_sub = temp_sub + right;
			}
		}

		//assert
		if (!isFound)
		{
			throw std::logic_error("out of mul");
		}

		CLongNumber temp_result = firstN - temp_sub;


		if (temp_result != CLongNumber("0"))
		{
			if (temp_result.m_data.size() == size_b)
			{
				++current_div_length;
			}
			if (!temp.m_data.empty())
			{
				temp.m_data.insert(temp.m_data.begin(), temp_result.m_data.begin(), temp_result.m_data.end());
			}
		}
		else
		{
			temp_result.m_data.clear();
		}

		int condition = size_b - temp_result.m_data.size() - 1;
		for (int j = 0; j < condition && j < temp.m_data.size(); ++j)
		{
			if (j != temp.m_data.size() - 1)
			{
				result.push_back(0);
			}
		}
	}
	return CLongNumber(result);
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

bool CLongNumber::operator!=(const CLongNumber & right) const
{
	return !(*this == right);
};

bool CLongNumber::operator>(const CLongNumber & right) const
{
	if (*this == right)
	{
		return false;
	}

	if (m_data.size() < right.m_data.size())
	{
		return false;
	}
	else if (m_data.size() > right.m_data.size())
	{
		return true;
	}

	for (size_t i = 0; i < m_data.size(); ++i)
	{
		if (this->m_data[i] == right.m_data[i])
		{

		}
		else if (this->m_data[i] > right.m_data[i])
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	return false;
};

bool CLongNumber::operator<(const CLongNumber & right) const
{
	if (*this == right || (*this > right))
	{
		return false;
	}
	return true;
};

void CLongNumber::AddNumber(std::vector<int> & vec, size_t position, int value)
{
	if (position >= vec.size())
	{
		vec.push_back(value);
		return;
	}

	int rest = 0;
	for (size_t i = position; i < vec.size(); ++i)
	{
		int result = vec[i] + value;
		rest = result / 10;
		vec[i] = result % 10;
		value = rest;
		if (rest == 0)
		{
			break;
		}
	}

	while (rest != 0)
	{
		vec.push_back(rest);
		rest /= 10;
	}
}

void CLongNumber::fillVectorWithZeroTillSize(std::vector<int> & vec, size_t size)
{
	while (vec.size() < size)
	{
		vec.push_back(0);
	}
}

std::vector<int> CLongNumber::getFirstNVec(const std::vector<int> & vec, size_t n)
{
	if (n > vec.size())
	{
		//throw std::logic_error("finish");
		return vec;
	}

	return std::vector<int>(vec.begin(), vec.begin() + n);
}