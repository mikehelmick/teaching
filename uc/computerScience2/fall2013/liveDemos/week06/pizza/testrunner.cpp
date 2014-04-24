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
#include "/Users/helmicmt/src/teaching/CS2/cs1022/week06/pizza/topping_test.h"

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

#include "/Users/helmicmt/src/teaching/CS2/cs1022/week06/pizza/pizza_test.h"

static PizzaTest suite_PizzaTest;

static CxxTest::List Tests_PizzaTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_PizzaTest( "pizza_test.h", 8, "PizzaTest", suite_PizzaTest, Tests_PizzaTest );

static class TestDescription_suite_PizzaTest_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PizzaTest_testConstructor() : CxxTest::RealTestDescription( Tests_PizzaTest, suiteDescription_PizzaTest, 10, "testConstructor" ) {}
 void runTest() { suite_PizzaTest.testConstructor(); }
} testDescription_suite_PizzaTest_testConstructor;

static class TestDescription_suite_PizzaTest_testAddOneTopping : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PizzaTest_testAddOneTopping() : CxxTest::RealTestDescription( Tests_PizzaTest, suiteDescription_PizzaTest, 11, "testAddOneTopping" ) {}
 void runTest() { suite_PizzaTest.testAddOneTopping(); }
} testDescription_suite_PizzaTest_testAddOneTopping;

static class TestDescription_suite_PizzaTest_testAddOnePremiumTopping : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PizzaTest_testAddOnePremiumTopping() : CxxTest::RealTestDescription( Tests_PizzaTest, suiteDescription_PizzaTest, 12, "testAddOnePremiumTopping" ) {}
 void runTest() { suite_PizzaTest.testAddOnePremiumTopping(); }
} testDescription_suite_PizzaTest_testAddOnePremiumTopping;

static class TestDescription_suite_PizzaTest_testAddTwoToppings : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PizzaTest_testAddTwoToppings() : CxxTest::RealTestDescription( Tests_PizzaTest, suiteDescription_PizzaTest, 13, "testAddTwoToppings" ) {}
 void runTest() { suite_PizzaTest.testAddTwoToppings(); }
} testDescription_suite_PizzaTest_testAddTwoToppings;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
