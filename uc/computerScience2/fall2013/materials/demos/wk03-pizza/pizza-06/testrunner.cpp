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
bool suite_ToppingTest_init = false;
#include "/Users/helmicmt/src/teaching/CS2/CS2-Fall2013/demos/wk03-pizza/pizza-06/topping_test.h"

static ToppingTest suite_ToppingTest;

static CxxTest::List Tests_ToppingTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ToppingTest( "topping_test.h", 5, "ToppingTest", suite_ToppingTest, Tests_ToppingTest );

static class TestDescription_suite_ToppingTest_testNonPreimumByDefault : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ToppingTest_testNonPreimumByDefault() : CxxTest::RealTestDescription( Tests_ToppingTest, suiteDescription_ToppingTest, 7, "testNonPreimumByDefault" ) {}
 void runTest() { suite_ToppingTest.testNonPreimumByDefault(); }
} testDescription_suite_ToppingTest_testNonPreimumByDefault;

static class TestDescription_suite_ToppingTest_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ToppingTest_testConstructor() : CxxTest::RealTestDescription( Tests_ToppingTest, suiteDescription_ToppingTest, 12, "testConstructor" ) {}
 void runTest() { suite_ToppingTest.testConstructor(); }
} testDescription_suite_ToppingTest_testConstructor;

static class TestDescription_suite_ToppingTest_testGetName : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ToppingTest_testGetName() : CxxTest::RealTestDescription( Tests_ToppingTest, suiteDescription_ToppingTest, 17, "testGetName" ) {}
 void runTest() { suite_ToppingTest.testGetName(); }
} testDescription_suite_ToppingTest_testGetName;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
