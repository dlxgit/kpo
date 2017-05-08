#include "stdafx.h"
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
	CLongNumber rest("0");

	int count_miss = 0;
	int count_size_div = size_b;
	bool begin = true;

	int last_div_zero_beginning_count = 0;
	int res_copy_size = 0;
	try
	{
		//
		while (temp.m_data.size() >= size_b - count_miss || begin)
		{
			begin = false;

			bool checked = false;
			bool bad_result = false;
			for (size_t i = 0; i < 11; ++i)
			{
				std::string nStr = boost::lexical_cast<std::string>(i);
				CLongNumber firstN = CLongNumber(getFirstNVec(temp.m_data, res_copy_size + 1));
				if (firstN < right)
				{
					++res_copy_size;
					if (!result.empty())
					{
						result.push_back(0);
						if (firstN.m_data.size() >= right.m_data.size())
						{
							++count_size_div;
						}
						bad_result = true;
						if (firstN.m_data.size() >= right.m_data.size())
						{
							last_div_zero_beginning_count = 0;
						}
						else
						{
							last_div_zero_beginning_count--;
						}

						break;
					}
					else
					{
						++count_miss;
						if (firstN.m_data.size() >= right.m_data.size())
						{
							++count_size_div;
						}
						bad_result = true;
						last_div_zero_beginning_count = 0;
						break;
					}
				}

				CLongNumber tmp_sub = CLongNumber(right * CLongNumber(nStr));

				if (tmp_sub > firstN)
				{
					last_div_zero_beginning_count = 1;

					checked = true;
					result.push_back(i - 1);

					auto temp_right = (CLongNumber(boost::lexical_cast<std::string>(i - 1)) * right).GetData();

					int size_result = (firstN - temp_right).m_data.size();
					res_copy_size = size_result;
					int count_size_div_additional = 0;
					if (count_size_div == size_b + 1)
					{
						if (size_result != right.m_data.size())
						{
							count_size_div_additional = 1;
						}
						--count_size_div; //?
					}

					bool isLastOperation = temp.m_data.size() <= firstN.m_data.size();

					fillVectorWithZeroTillSize(temp_right, temp.m_data.size() - (firstN.m_data.size() - temp_right.size()));

					CLongNumber res = temp - CLongNumber(temp_right);
					last_div_zero_beginning_count = firstN.m_data.size() - size_result - count_size_div_additional;
					temp = res;

					if (temp < right)
					{
						if (temp != CLongNumber("0") && !isLastOperation)
						{
							result.push_back(0);
						}
						
						return result;
					}
					break;
				}
			}
			if (bad_result)
			{
				continue;
			}
			if (!checked)
			{
				result.push_back(0);
			}
		}
	}
	catch (std::logic_error)
	{
		result.push_back(0);
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
		throw std::logic_error("finish");
	}

	return std::vector<int>(vec.begin(), vec.begin() + n);
}