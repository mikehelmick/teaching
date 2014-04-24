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
bool suite_BigIntTest_init = false;
#include "/Users/helmicmt/src/teaching/CS2/CS2-Fall2013/homework/hw03-bigint/helmick/bigint_test.h"

static BigIntTest suite_BigIntTest;

static CxxTest::List Tests_BigIntTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_BigIntTest( "bigint_test.h", 5, "BigIntTest", suite_BigIntTest, Tests_BigIntTest );

static class TestDescription_suite_BigIntTest_testDefaultConstructorLong : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testDefaultConstructorLong() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 8, "testDefaultConstructorLong" ) {}
 void runTest() { suite_BigIntTest.testDefaultConstructorLong(); }
} testDescription_suite_BigIntTest_testDefaultConstructorLong;

static class TestDescription_suite_BigIntTest_testDefaultConstructorString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testDefaultConstructorString() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 13, "testDefaultConstructorString" ) {}
 void runTest() { suite_BigIntTest.testDefaultConstructorString(); }
} testDescription_suite_BigIntTest_testDefaultConstructorString;

static class TestDescription_suite_BigIntTest_testLongConstructorLong : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLongConstructorLong() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 18, "testLongConstructorLong" ) {}
 void runTest() { suite_BigIntTest.testLongConstructorLong(); }
} testDescription_suite_BigIntTest_testLongConstructorLong;

static class TestDescription_suite_BigIntTest_testLongtConstructorString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLongtConstructorString() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 23, "testLongtConstructorString" ) {}
 void runTest() { suite_BigIntTest.testLongtConstructorString(); }
} testDescription_suite_BigIntTest_testLongtConstructorString;

static class TestDescription_suite_BigIntTest_testEquality1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testEquality1() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 31, "testEquality1" ) {}
 void runTest() { suite_BigIntTest.testEquality1(); }
} testDescription_suite_BigIntTest_testEquality1;

static class TestDescription_suite_BigIntTest_testEquality2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testEquality2() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 36, "testEquality2" ) {}
 void runTest() { suite_BigIntTest.testEquality2(); }
} testDescription_suite_BigIntTest_testEquality2;

static class TestDescription_suite_BigIntTest_testEquality3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testEquality3() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 41, "testEquality3" ) {}
 void runTest() { suite_BigIntTest.testEquality3(); }
} testDescription_suite_BigIntTest_testEquality3;

static class TestDescription_suite_BigIntTest_testEquality4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testEquality4() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 46, "testEquality4" ) {}
 void runTest() { suite_BigIntTest.testEquality4(); }
} testDescription_suite_BigIntTest_testEquality4;

static class TestDescription_suite_BigIntTest_testEquality5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testEquality5() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 51, "testEquality5" ) {}
 void runTest() { suite_BigIntTest.testEquality5(); }
} testDescription_suite_BigIntTest_testEquality5;

static class TestDescription_suite_BigIntTest_testLess1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess1() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 58, "testLess1" ) {}
 void runTest() { suite_BigIntTest.testLess1(); }
} testDescription_suite_BigIntTest_testLess1;

static class TestDescription_suite_BigIntTest_testLess2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess2() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 63, "testLess2" ) {}
 void runTest() { suite_BigIntTest.testLess2(); }
} testDescription_suite_BigIntTest_testLess2;

static class TestDescription_suite_BigIntTest_testLess3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess3() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 68, "testLess3" ) {}
 void runTest() { suite_BigIntTest.testLess3(); }
} testDescription_suite_BigIntTest_testLess3;

static class TestDescription_suite_BigIntTest_testLess4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess4() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 74, "testLess4" ) {}
 void runTest() { suite_BigIntTest.testLess4(); }
} testDescription_suite_BigIntTest_testLess4;

static class TestDescription_suite_BigIntTest_testLess5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess5() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 81, "testLess5" ) {}
 void runTest() { suite_BigIntTest.testLess5(); }
} testDescription_suite_BigIntTest_testLess5;

static class TestDescription_suite_BigIntTest_testLess6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess6() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 86, "testLess6" ) {}
 void runTest() { suite_BigIntTest.testLess6(); }
} testDescription_suite_BigIntTest_testLess6;

static class TestDescription_suite_BigIntTest_testLess7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess7() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 91, "testLess7" ) {}
 void runTest() { suite_BigIntTest.testLess7(); }
} testDescription_suite_BigIntTest_testLess7;

static class TestDescription_suite_BigIntTest_testLess8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testLess8() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 97, "testLess8" ) {}
 void runTest() { suite_BigIntTest.testLess8(); }
} testDescription_suite_BigIntTest_testLess8;

static class TestDescription_suite_BigIntTest_testCompareTo1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo1() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 105, "testCompareTo1" ) {}
 void runTest() { suite_BigIntTest.testCompareTo1(); }
} testDescription_suite_BigIntTest_testCompareTo1;

static class TestDescription_suite_BigIntTest_testCompareTo2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo2() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 112, "testCompareTo2" ) {}
 void runTest() { suite_BigIntTest.testCompareTo2(); }
} testDescription_suite_BigIntTest_testCompareTo2;

static class TestDescription_suite_BigIntTest_testCompareTo3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo3() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 119, "testCompareTo3" ) {}
 void runTest() { suite_BigIntTest.testCompareTo3(); }
} testDescription_suite_BigIntTest_testCompareTo3;

static class TestDescription_suite_BigIntTest_testCompareTo4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo4() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 126, "testCompareTo4" ) {}
 void runTest() { suite_BigIntTest.testCompareTo4(); }
} testDescription_suite_BigIntTest_testCompareTo4;

static class TestDescription_suite_BigIntTest_testCompareTo5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo5() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 132, "testCompareTo5" ) {}
 void runTest() { suite_BigIntTest.testCompareTo5(); }
} testDescription_suite_BigIntTest_testCompareTo5;

static class TestDescription_suite_BigIntTest_testCompareTo6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo6() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 138, "testCompareTo6" ) {}
 void runTest() { suite_BigIntTest.testCompareTo6(); }
} testDescription_suite_BigIntTest_testCompareTo6;

static class TestDescription_suite_BigIntTest_testCompareTo7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo7() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 144, "testCompareTo7" ) {}
 void runTest() { suite_BigIntTest.testCompareTo7(); }
} testDescription_suite_BigIntTest_testCompareTo7;

static class TestDescription_suite_BigIntTest_testCompareTo8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testCompareTo8() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 151, "testCompareTo8" ) {}
 void runTest() { suite_BigIntTest.testCompareTo8(); }
} testDescription_suite_BigIntTest_testCompareTo8;

static class TestDescription_suite_BigIntTest_testAdd1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testAdd1() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 158, "testAdd1" ) {}
 void runTest() { suite_BigIntTest.testAdd1(); }
} testDescription_suite_BigIntTest_testAdd1;

static class TestDescription_suite_BigIntTest_testAdd2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testAdd2() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 165, "testAdd2" ) {}
 void runTest() { suite_BigIntTest.testAdd2(); }
} testDescription_suite_BigIntTest_testAdd2;

static class TestDescription_suite_BigIntTest_testAdd3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testAdd3() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 172, "testAdd3" ) {}
 void runTest() { suite_BigIntTest.testAdd3(); }
} testDescription_suite_BigIntTest_testAdd3;

static class TestDescription_suite_BigIntTest_testAdd4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testAdd4() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 179, "testAdd4" ) {}
 void runTest() { suite_BigIntTest.testAdd4(); }
} testDescription_suite_BigIntTest_testAdd4;

static class TestDescription_suite_BigIntTest_testAdd5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testAdd5() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 186, "testAdd5" ) {}
 void runTest() { suite_BigIntTest.testAdd5(); }
} testDescription_suite_BigIntTest_testAdd5;

static class TestDescription_suite_BigIntTest_testAdd6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BigIntTest_testAdd6() : CxxTest::RealTestDescription( Tests_BigIntTest, suiteDescription_BigIntTest, 193, "testAdd6" ) {}
 void runTest() { suite_BigIntTest.testAdd6(); }
} testDescription_suite_BigIntTest_testAdd6;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
