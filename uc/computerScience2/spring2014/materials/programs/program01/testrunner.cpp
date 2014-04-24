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
bool suite_FractionTest_init = false;
#include "FractionTest.h"

static FractionTest suite_FractionTest;

static CxxTest::List Tests_FractionTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_FractionTest( "FractionTest.h", 11, "FractionTest", suite_FractionTest, Tests_FractionTest );

static class TestDescription_suite_FractionTest_testToString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testToString() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 14, "testToString" ) {}
 void runTest() { suite_FractionTest.testToString(); }
} testDescription_suite_FractionTest_testToString;

static class TestDescription_suite_FractionTest_testToString2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testToString2() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 19, "testToString2" ) {}
 void runTest() { suite_FractionTest.testToString2(); }
} testDescription_suite_FractionTest_testToString2;

static class TestDescription_suite_FractionTest_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testAddition() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 24, "testAddition" ) {}
 void runTest() { suite_FractionTest.testAddition(); }
} testDescription_suite_FractionTest_testAddition;

static class TestDescription_suite_FractionTest_testAdditionDifferentBase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testAdditionDifferentBase() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 33, "testAdditionDifferentBase" ) {}
 void runTest() { suite_FractionTest.testAdditionDifferentBase(); }
} testDescription_suite_FractionTest_testAdditionDifferentBase;

static class TestDescription_suite_FractionTest_testSubtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testSubtraction() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 41, "testSubtraction" ) {}
 void runTest() { suite_FractionTest.testSubtraction(); }
} testDescription_suite_FractionTest_testSubtraction;

static class TestDescription_suite_FractionTest_testSubtractionNegative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testSubtractionNegative() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 49, "testSubtractionNegative" ) {}
 void runTest() { suite_FractionTest.testSubtractionNegative(); }
} testDescription_suite_FractionTest_testSubtractionNegative;

static class TestDescription_suite_FractionTest_testSubtractionDifferentBase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testSubtractionDifferentBase() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 57, "testSubtractionDifferentBase" ) {}
 void runTest() { suite_FractionTest.testSubtractionDifferentBase(); }
} testDescription_suite_FractionTest_testSubtractionDifferentBase;

static class TestDescription_suite_FractionTest_testMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testMultiplication() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 65, "testMultiplication" ) {}
 void runTest() { suite_FractionTest.testMultiplication(); }
} testDescription_suite_FractionTest_testMultiplication;

static class TestDescription_suite_FractionTest_testMultiplication2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testMultiplication2() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 73, "testMultiplication2" ) {}
 void runTest() { suite_FractionTest.testMultiplication2(); }
} testDescription_suite_FractionTest_testMultiplication2;

static class TestDescription_suite_FractionTest_testDivision : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testDivision() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 81, "testDivision" ) {}
 void runTest() { suite_FractionTest.testDivision(); }
} testDescription_suite_FractionTest_testDivision;

static class TestDescription_suite_FractionTest_testDivision2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testDivision2() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 89, "testDivision2" ) {}
 void runTest() { suite_FractionTest.testDivision2(); }
} testDescription_suite_FractionTest_testDivision2;

static class TestDescription_suite_FractionTest_testZeroAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testZeroAddition() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 97, "testZeroAddition" ) {}
 void runTest() { suite_FractionTest.testZeroAddition(); }
} testDescription_suite_FractionTest_testZeroAddition;

static class TestDescription_suite_FractionTest_testZeroSubtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FractionTest_testZeroSubtraction() : CxxTest::RealTestDescription( Tests_FractionTest, suiteDescription_FractionTest, 105, "testZeroSubtraction" ) {}
 void runTest() { suite_FractionTest.testZeroSubtraction(); }
} testDescription_suite_FractionTest_testZeroSubtraction;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
