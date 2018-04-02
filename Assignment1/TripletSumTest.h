#ifndef TRIPLET_SUM_TEST_H
#define TRIPLET_SUM_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TripletSumTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( TripletSumTest );
	CPPUNIT_TEST( testTripletSum );
	CPPUNIT_TEST_SUITE_END();

public:
    void testTripletSum(void);
};
#endif
