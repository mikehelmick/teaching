/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_ShipTest_init = false;
#include "/Users/helmicmt/src/teaching/CS2/cs1022/week04/battleship/ship_test.h"

static ShipTest suite_ShipTest;

static CxxTest::List Tests_ShipTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ShipTest( "ship_test.h", 8, "ShipTest", suite_ShipTest, Tests_ShipTest );

static class TestDescription_suite_ShipTest_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ShipTest_testConstructor() : CxxTest::RealTestDescription( Tests_ShipTest, suiteDescription_ShipTest, 11, "testConstructor" ) {}
 void runTest() { suite_ShipTest.testConstructor(); }
} testDescription_suite_ShipTest_testConstructor;

static class TestDescription_suite_ShipTest_testGetSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ShipTest_testGetSize() : CxxTest::RealTestDescription( Tests_ShipTest, suiteDescription_ShipTest, 15, "testGetSize" ) {}
 void runTest() { suite_ShipTest.testGetSize(); }
} testDescription_suite_ShipTest_testGetSize;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
