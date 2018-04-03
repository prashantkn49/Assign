#include "InviteFriends.h"
#include "InviteFriendsTest.h"

using namespace std;
CPPUNIT_TEST_SUITE_REGISTRATION ( InviteFriendsTest );

void InviteFriendsTest::testInviteFriends(void)
{
    InviteFriends inviteFriends;

    string fileName = "friends1.json";

    if ( !inviteFriends.readFile(fileName) )
    {
        cout << "Cannot read the file\n\n";
    }

    vector < friendInfo > friendsComingToParty = inviteFriends.getFriendInfo();

    for ( int i = 0; i < friendsComingToParty.size(); ++i )
    {
        CPPUNIT_ASSERT(friendsComingToParty[i].distance <= 100.0);
    }

    fileName = "friends2.json";

    bool failed = false;

    if ( !inviteFriends.readFile(fileName) )
	{
        cout << "Cannot read the file\n\n";
        failed = true;
	}

	CPPUNIT_ASSERT(failed == false);

	friendsComingToParty = inviteFriends.getFriendInfo();

    for ( int i = 0; i < friendsComingToParty.size(); ++i )
    {
        CPPUNIT_ASSERT(friendsComingToParty[i].distance <= 100.0);
    }

    fileName = "friends3.json";

    failed = false;

    if ( !inviteFriends.readFile(fileName) )
    {
        cout << "Cannot read the file\n\n";
        failed = true;
    }

    CPPUNIT_ASSERT(failed == false);

    friendsComingToParty = inviteFriends.getFriendInfo();

    for ( int i = 0; i < friendsComingToParty.size(); ++i )
    {
        CPPUNIT_ASSERT(friendsComingToParty[i].distance <= 100.0);
    }

    failed = false;

    fileName = "frinds4.json";

    if ( !inviteFriends.readFile(fileName) )
    {
        cout << "Cannot read the file\n\n";
        failed = true;
    }

    CPPUNIT_ASSERT(failed == true);
}
