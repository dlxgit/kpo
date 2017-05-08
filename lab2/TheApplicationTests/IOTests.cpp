
#include "stdafx.h"
#include "../LongArithmetics/LongNumberExpression.h"

BOOST_AUTO_TEST_SUITE(expression_parsing)
BOOST_AUTO_TEST_CASE(asd)
{
	BOOST_REQUIRE_NO_THROW(CLongNumberExpression("3+35"));
}

BOOST_AUTO_TEST_SUITE_END()
