// TheApplicationTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../LongArithmetics/LongNumber.h"


BOOST_AUTO_TEST_SUITE(operator_plus)
	BOOST_AUTO_TEST_CASE(same_size)
	{
		BOOST_CHECK_EQUAL(CLongNumber("1234") + CLongNumber("1234"), CLongNumber("2468"));
	}

	BOOST_AUTO_TEST_CASE(size_1_less_than_2)
	{
		BOOST_CHECK_EQUAL(CLongNumber("1234") + CLongNumber("12345"), CLongNumber("13579"));
	}

	BOOST_AUTO_TEST_CASE(size_2_less_than_1)
	{
		BOOST_CHECK_EQUAL(CLongNumber("12345") + CLongNumber("1234"), CLongNumber("13579"));
	}

	BOOST_AUTO_TEST_CASE(same_size_with_over)
	{
		BOOST_CHECK_EQUAL(CLongNumber("12345") + CLongNumber("12345"), CLongNumber("24690"));
	}

	BOOST_AUTO_TEST_CASE(zero_in_beginning)
	{
		BOOST_CHECK_EQUAL(CLongNumber("100") + CLongNumber("100"), CLongNumber("200"));
	}

	BOOST_AUTO_TEST_CASE(over_in_beginning)
	{
		BOOST_CHECK_EQUAL(CLongNumber("9") + CLongNumber("1"), CLongNumber("10"));
	}
	BOOST_AUTO_TEST_CASE(overs_in_beginning)
	{
		BOOST_CHECK_EQUAL(CLongNumber("99") + CLongNumber("1"), CLongNumber("100"));
	}
	BOOST_AUTO_TEST_CASE(one_in_beginning)
	{
		BOOST_CHECK_EQUAL(CLongNumber("9") + CLongNumber("0"), CLongNumber("9"));
	}
	BOOST_AUTO_TEST_CASE(zero_in_beginning1)
	{
		BOOST_CHECK_EQUAL(CLongNumber("0") + CLongNumber("0"), CLongNumber("0"));
	}
BOOST_AUTO_TEST_SUITE_END()




BOOST_AUTO_TEST_SUITE(operator_minus)
BOOST_AUTO_TEST_CASE(same_size)
{
	BOOST_CHECK_EQUAL(CLongNumber("1234") - CLongNumber("1234"), CLongNumber("0"));
}

// BOOST_AUTO_TEST_CASE(size_1_less_than_2)
// {
// 	BOOST_CHECK_EQUAL(CLongNumber("1234") - CLongNumber("12345"), CLongNumber("1111"));
// }

BOOST_AUTO_TEST_CASE(size_2_less_than_1)
{
	BOOST_CHECK_EQUAL(CLongNumber("12345") - CLongNumber("1234"), CLongNumber("11111"));
}

BOOST_AUTO_TEST_CASE(size_2_less_than_11)
{
	BOOST_CHECK_EQUAL(CLongNumber("100") - CLongNumber("100"), CLongNumber("0"));
}

BOOST_AUTO_TEST_CASE(size_2_less_than_111)
{
	BOOST_CHECK_EQUAL(CLongNumber("200") - CLongNumber("100"), CLongNumber("100"));
}

BOOST_AUTO_TEST_CASE(size_2_less_than_1111)
{
	BOOST_CHECK_EQUAL(CLongNumber("2000") - CLongNumber("100"), CLongNumber("1900"));
}

BOOST_AUTO_TEST_CASE(same_size_with_over)
{
	BOOST_CHECK_EQUAL(CLongNumber("12345") - CLongNumber("2346"), CLongNumber("9999"));
}

BOOST_AUTO_TEST_CASE(same_size_with_over1)
{
	BOOST_CHECK_EQUAL(CLongNumber("345") - CLongNumber("47"), CLongNumber("298"));
}

BOOST_AUTO_TEST_CASE(over_in_beginning)
{
	BOOST_CHECK_EQUAL(CLongNumber("9") - CLongNumber("1"), CLongNumber("8"));
}
BOOST_AUTO_TEST_CASE(overs_in_beginning2)
{
	BOOST_CHECK_EQUAL(CLongNumber("11") - CLongNumber("2"), CLongNumber("9"));
}
BOOST_AUTO_TEST_CASE(one_in_beginning3)
{
	BOOST_CHECK_EQUAL(CLongNumber("101") - CLongNumber("92"), CLongNumber("9"));
}
BOOST_AUTO_TEST_CASE(one_in_beginning4)
{
	BOOST_CHECK_EQUAL(CLongNumber("101") - CLongNumber("99"), CLongNumber("2"));
}
BOOST_AUTO_TEST_CASE(zero_in_beginning5)
{
	BOOST_CHECK_EQUAL(CLongNumber("0") - CLongNumber("0"), CLongNumber("0"));
}
BOOST_AUTO_TEST_SUITE_END()



