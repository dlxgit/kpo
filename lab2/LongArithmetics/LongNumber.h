#pragma once
#include <vector>
#include <iostream>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/lexical_cast.hpp>

class CLongNumber
{
public:
	CLongNumber(const std::string & data)
	{
		m_data.clear();
		
		for (auto el : data)
		{
			m_data.push_back(boost::lexical_cast<int>(el));
		}
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
			return false;
		}
		
		for (size_t i = 0; i < m_data.size(); ++i)
		{
			if (this->m_data[i] > right.m_data[i])
			{
				return true;
			}
		}
		return false;
	};

	bool operator<(const CLongNumber & right) const
	{
		if (*this == right || !(*this > right))
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
};