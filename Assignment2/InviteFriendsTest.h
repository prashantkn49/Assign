#ifndef TRIPLET_SUM_TEST_H
#define TRIPLET_SUM_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class InviteFriendsTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( InviteFriendsTest );
	CPPUNIT_TEST( testInviteFriends );
	CPPUNIT_TEST_SUITE_END();

public:
    void testInviteFriends();
};
#endif
