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
bool suite_GradebookTest_init = false;
#include "/Users/helmicmt/src/teaching/CS2/cs1022/solutions/hw04-testscores/helmick/GradebookTest.h"

static GradebookTest suite_GradebookTest;

static CxxTest::List Tests_GradebookTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_GradebookTest( "GradebookTest.h", 8, "GradebookTest", suite_GradebookTest, Tests_GradebookTest );

static class TestDescription_suite_GradebookTest_testAddOne : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GradebookTest_testAddOne() : CxxTest::RealTestDescription( Tests_GradebookTest, suiteDescription_GradebookTest, 10, "testAddOne" ) {}
 void runTest() { suite_GradebookTest.testAddOne(); }
} testDescription_suite_GradebookTest_testAddOne;

static class TestDescription_suite_GradebookTest_testAddMultiple : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GradebookTest_testAddMultiple() : CxxTest::RealTestDescription( Tests_GradebookTest, suiteDescription_GradebookTest, 17, "testAddMultiple" ) {}
 void runTest() { suite_GradebookTest.testAddMultiple(); }
} testDescription_suite_GradebookTest_testAddMultiple;

static class TestDescription_suite_GradebookTest_testAddALot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GradebookTest_testAddALot() : CxxTest::RealTestDescription( Tests_GradebookTest, suiteDescription_GradebookTest, 26, "testAddALot" ) {}
 void runTest() { suite_GradebookTest.testAddALot(); }
} testDescription_suite_GradebookTest_testAddALot;

static class TestDescription_suite_GradebookTest_testStdDev : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GradebookTest_testStdDev() : CxxTest::RealTestDescription( Tests_GradebookTest, suiteDescription_GradebookTest, 38, "testStdDev" ) {}
 void runTest() { suite_GradebookTest.testStdDev(); }
} testDescription_suite_GradebookTest_testStdDev;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
