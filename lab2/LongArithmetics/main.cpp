#include "LongNumber.h"
#include <iostream>




/*
	beginning with 0 (one or many)

	negative results
*/
int main()
{

	CLongNumber a = CLongNumber("1201") / CLongNumber("11");
	std::cout << a;

	return 0;
}