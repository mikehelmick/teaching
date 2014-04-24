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
bool suite_PersonTest_init = false;
#include "PersonTest.h"

static PersonTest suite_PersonTest;

static CxxTest::List Tests_PersonTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_PersonTest( "PersonTest.h", 11, "PersonTest", suite_PersonTest, Tests_PersonTest );

static class TestDescription_suite_PersonTest_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testConstructor() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 20, "testConstructor" ) {}
 void runTest() { suite_PersonTest.testConstructor(); }
} testDescription_suite_PersonTest_testConstructor;

static class TestDescription_suite_PersonTest_testInvalidDir : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testInvalidDir() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 25, "testInvalidDir" ) {}
 void runTest() { suite_PersonTest.testInvalidDir(); }
} testDescription_suite_PersonTest_testInvalidDir;

static class TestDescription_suite_PersonTest_testInvalidSteps : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testInvalidSteps() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 31, "testInvalidSteps" ) {}
 void runTest() { suite_PersonTest.testInvalidSteps(); }
} testDescription_suite_PersonTest_testInvalidSteps;

static class TestDescription_suite_PersonTest_testXMovement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testXMovement() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 37, "testXMovement" ) {}
 void runTest() { suite_PersonTest.testXMovement(); }
} testDescription_suite_PersonTest_testXMovement;

static class TestDescription_suite_PersonTest_testYMovement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testYMovement() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 45, "testYMovement" ) {}
 void runTest() { suite_PersonTest.testYMovement(); }
} testDescription_suite_PersonTest_testYMovement;

static class TestDescription_suite_PersonTest_testMoveNE : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testMoveNE() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 53, "testMoveNE" ) {}
 void runTest() { suite_PersonTest.testMoveNE(); }
} testDescription_suite_PersonTest_testMoveNE;

static class TestDescription_suite_PersonTest_testMoveNW : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testMoveNW() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 59, "testMoveNW" ) {}
 void runTest() { suite_PersonTest.testMoveNW(); }
} testDescription_suite_PersonTest_testMoveNW;

static class TestDescription_suite_PersonTest_testMoveSE : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testMoveSE() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 65, "testMoveSE" ) {}
 void runTest() { suite_PersonTest.testMoveSE(); }
} testDescription_suite_PersonTest_testMoveSE;

static class TestDescription_suite_PersonTest_testMoveSW : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testMoveSW() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 71, "testMoveSW" ) {}
 void runTest() { suite_PersonTest.testMoveSW(); }
} testDescription_suite_PersonTest_testMoveSW;

static class TestDescription_suite_PersonTest_testTour : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PersonTest_testTour() : CxxTest::RealTestDescription( Tests_PersonTest, suiteDescription_PersonTest, 77, "testTour" ) {}
 void runTest() { suite_PersonTest.testTour(); }
} testDescription_suite_PersonTest_testTour;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
