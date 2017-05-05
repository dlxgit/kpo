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
	


	friend std::ostream & operator<<(std::ostream & os, const CLongNumber & longNumber);

private:

	std::vector<int> m_data;

};