#include <cppunit/extensions/HelperMacros.h>

#include "TripletSum.h"
#include "TripletSumTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION ( TripletSumTest );

void TripletSumTest::testTripletSum(void)
{
	TripletSum tripletSum;

	vector<int> data {1,1,1};
	int targetSum = 3;

	tripletSum.setData(data);
	tripletSum.setTargetSum(targetSum);

	// Data = {1, 1, 1} and targetSum = 3
	CPPUNIT_ASSERT(tripletSum.checkTargetSum() == true);

	data.push_back(123456787);
	targetSum = 123456789;

	// Data = {1, 1, 1,123456787} and targetSum = 123456789
	tripletSum.setData(data);
	tripletSum.setTargetSum(targetSum);

	CPPUNIT_ASSERT(tripletSum.checkTargetSum() == true);

	data.pop_back();
	data.push_back(2147483647);

	tripletSum.setData(data);

	// Data = {1, 1, 1, 2147483647} and targetSum = 123456789
	// 2147483647 is the maximum integer value
	CPPUNIT_ASSERT(tripletSum.checkTargetSum() == false);

	data.pop_back();
	data.push_back(2);
	targetSum = 4;

	tripletSum.setData(data);
	tripletSum.setTargetSum(targetSum);

	// Data = {1, 1, 1, 2} and targetSum = 4
	CPPUNIT_ASSERT(tripletSum.checkTargetSum() == true);

	vector<int> elements = tripletSum.getElements();

	long long sum = elements[0] + elements[1] + elements[2];

	CPPUNIT_ASSERT(sum == targetSum);
}
