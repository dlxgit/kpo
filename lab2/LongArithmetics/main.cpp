#include "LongNumber.h"
#include <iostream>




/*
	beginning with 0 (one or many)

	negative results
*/
int main()
{

	CLongNumber a = CLongNumber("20") * CLongNumber("0");
	std::cout << a;

	return 0;
}