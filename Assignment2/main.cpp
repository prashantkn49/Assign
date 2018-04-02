#include "InviteFriends.h"
#include "InviteFriendsTest.h"

#include <cppunit/ui/text/TestRunner.h>

int main( int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( InviteFriendsTest::suite() );
    return runner.run();
}