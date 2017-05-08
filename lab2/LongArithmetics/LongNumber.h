#pragma once
#include <vector>
#include <iostream>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/lexical_cast.hpp>
#include <locale>

class CLongNumber
{
public:
	CLongNumber() = default;
	CLongNumber(const std::string & data)
	{
		//?
		m_data.clear();
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

	CLongNumber(const CLongNumber & other)
		:m_data(other.m_data)
	{
		
	};

	CLongNumber(const std::vector<int> & data)
		:m_data(data)
	{

	};

	std::vector<int> GetData() const;

	CLongNumber operator+(const CLongNumber & right) const;
	CLongNumber operator-(const CLongNumber & right) const;
	CLongNumber operator*(const CLongNumber & right) const;
	CLongNumber operator/(const CLongNumber & right) const;
	
	bool operator==(const CLongNumber & right) const;

	bool operator!=(const CLongNumber & right) const
	{
		return !(*this == right);
	};

	bool operator>(const CLongNumber & right) const
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

	bool operator<(const CLongNumber & right) const
	{
		if (*this == right || (*this > right))
		{
			return false;
		}
		return true;
	};


	friend std::ostream & operator<<(std::ostream & os, const CLongNumber & longNumber);

private:

	std::vector<int> m_data;

	//operation +
	//works for inverted vec
	static void AddNumber(std::vector<int> & vec, size_t position, int value)
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
			//rest = result > 9 ? 1 : 0;
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

	static void fillVectorWithZeroTillSize(std::vector<int> & vec, size_t size)
	{
		while (vec.size() < size)
		{
			vec.push_back(0);
		}
	}
	static std::vector<int> getFirstNVec(const std::vector<int> & vec, size_t n)
	{
		if (n > vec.size())
		{
			throw std::logic_error("finish");
		}

		return std::vector<int>(vec.begin(), vec.begin() + n);
	}
};