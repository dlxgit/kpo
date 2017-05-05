#include "LongNumber.h"
#include <iostream>





int main()
{
	CLongNumber a = CLongNumber("15") + CLongNumber("15");
	std::cout << a;

	return 0;
}