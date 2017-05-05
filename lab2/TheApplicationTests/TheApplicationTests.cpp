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
	BOOST_AUTO_TEST_CASE(zero_in_beginning)
	{
		BOOST_CHECK_EQUAL(CLongNumber("0") + CLongNumber("0"), CLongNumber("0"));
	}

// BOOST_AUTO_TEST_CASE(asd)
// {
// 	BOOST_CHECK_EQUAL(1, 1);
// }
BOOST_AUTO_TEST_SUITE_END()