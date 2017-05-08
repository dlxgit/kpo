#include "LongNumber.h"
#include <iostream>




/*
	beginning with 0 (one or many)

	negative results
*/
int main()
{
	CLongNumber("0000");
	//CLongNumber a = CLongNumber("1201") / CLongNumber("11");
	//CLongNumber a = CLongNumber("1034") / CLongNumber("11");
	//CLongNumber a = CLongNumber("12") - CLongNumber("123");
	CLongNumber a = CLongNumber("42352152556") / CLongNumber("384716");////;////CLongNumber("20") / CLongNumber("10");//CLongNumber("1201") / CLongNumber("11");//
	std::cout << a;

	return 0;
}