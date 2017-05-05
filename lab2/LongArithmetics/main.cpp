#include "LongNumber.h"
#include <iostream>





int main()
{

	CLongNumber a = CLongNumber("345") - CLongNumber("47");
	std::cout << a;

	return 0;
}