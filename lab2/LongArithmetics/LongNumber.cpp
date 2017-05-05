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

		int firstOperand;
		int secondOperand;
		firstOperand = index >= size_a ? 0 : a[index];
		secondOperand = index >= size_b ?  0 : b[index];

		int resValue = firstOperand + secondOperand + rest;
		rest = (resValue > 9) ? resValue - 9 : 0;
		result.push_back(resValue % 10);
		
		
// 		if (index == size_a - 1)
// 		{
// 			if (b.size() > 0)
// 			{
// 				result.push_back((b[0] + rest))
// 			}
// 			result.insert(result.end(), b.begin() + index + 2, b.end());
// 			break;
// 		}
// 		else if (index == size_b - 1)
// 		{
// 			result.insert(result.end(), a.begin() + index + 2, a.end());
// 			break;
// 		}
	}
	if (rest != 0)
	{
		result.push_back(rest);
	}

	std::reverse(result.begin(), result.end());

	return CLongNumber(result);

// 	// определяем длину массива суммы
// 	if (size_a > size_b)
// 		length = size_a + 1;
// 	else
// 		length = size_b + 1;
// 
// 	for (int ix = 0; ix < length; ix++)
// 	{
// 		b[ix] += a[ix]; // суммируем последние разряды чисел
// 		b[ix + 1] += (b[ix] / 10); // если есть разряд для переноса, переносим его в следующий разряд
// 		b[ix] %= 10; // если есть разряд для переноса он отсекается
// 	}
// 
// 	if (b[length - 1] == 0)
// 		length--;
}

CLongNumber CLongNumber::operator-(const CLongNumber & right) const
{
// 	int k = 3; // если к == 3, значит числа одинаковой длинны
// 	std::vector<int> a = this->GetData();
// 	std::reverse(a.end(), a.begin());
// 	int size_a = a.size();
// 
// 	std::vector<int> b = right.GetData();
// 	std::reverse(b.end(), b.begin());
// 	int size_b = b.size();
// 
// 	int length = size_a;
// 	if (size_a > size_b)
// 	{
// 		length = size_a;
// 		k = 1; // если к == 1, значит первое число длиннее второго
// 	}
// 	else
// 		if (size_b > size_a)
// 		{
// 			length = size_b;
// 			k = 2; // если к == 2, значит второе число длиннее первого
// 		}
// 		else // если числа одинаковой длинны, то необходимо сравнить их веса
// 			for (int ix = 0; ix < length;) // поразрядное сравнение весов чисел
// 			{
// 				if (a[ix] > b[ix]) // если разряд первого числа больше
// 				{
// 					k = 1; // значит первое число длиннее второго
// 					break; // выход из цикла for
// 				}
// 
// 				if (b[ix] > a[ix]) // если разряд второго числа больше
// 				{
// 					k = 2; // значит второе число длиннее первого
// 					break; // выход из цикла for
// 				}
// 			} // конец for

	return CLongNumber(std::vector<int>());
}

CLongNumber CLongNumber::operator*(const CLongNumber & right) const
{
	return CLongNumber(std::vector<int>(1));
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