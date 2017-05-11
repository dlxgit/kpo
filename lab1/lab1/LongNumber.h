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
	CLongNumber(const std::string & data);
	CLongNumber(const CLongNumber & other);
	CLongNumber(const std::vector<int> & data);

	std::vector<int> GetData() const;
	std::string ToString() const;
	CLongNumber operator+(const CLongNumber & right) const;
	CLongNumber operator-(const CLongNumber & right) const;
	CLongNumber operator*(const CLongNumber & right) const;
	CLongNumber operator/(const CLongNumber & right) const;
	
	bool operator==(const CLongNumber & right) const;
	bool operator!=(const CLongNumber & right) const;
	bool operator>(const CLongNumber & right) const;
	bool operator<(const CLongNumber & right) const;

	friend std::ostream & operator<<(std::ostream & os, const CLongNumber & longNumber);

private:

	std::vector<int> m_data;

	//operation +
	//works for inverted vec
	static void AddNumber(std::vector<int> & vec, size_t position, int value);
	static void fillVectorWithZeroTillSize(std::vector<int> & vec, size_t size);
	static std::vector<int> getFirstNVec(const std::vector<int> & vec, size_t n);
};