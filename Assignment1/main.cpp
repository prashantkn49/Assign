#include "TripletSum.h"
#include "TripletSumTest.h"

#include <cppunit/ui/text/TestRunner.h>

int main( int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TripletSumTest::suite() );
    return runner.run("", true);
}