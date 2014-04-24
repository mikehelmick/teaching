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
bool suite_GameTest_init = false;
#include "/Users/helmicmt/src/teaching/CS2/cs1022/solutions/hw05-bowling/GameTest.h"

static GameTest suite_GameTest;

static CxxTest::List Tests_GameTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_GameTest( "GameTest.h", 12, "GameTest", suite_GameTest, Tests_GameTest );

static class TestDescription_suite_GameTest_testWeirdGame : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testWeirdGame() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 36, "testWeirdGame" ) {}
 void runTest() { suite_GameTest.testWeirdGame(); }
} testDescription_suite_GameTest_testWeirdGame;

static class TestDescription_suite_GameTest_testGameCompleteCorrectly : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testGameCompleteCorrectly() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 54, "testGameCompleteCorrectly" ) {}
 void runTest() { suite_GameTest.testGameCompleteCorrectly(); }
} testDescription_suite_GameTest_testGameCompleteCorrectly;

static class TestDescription_suite_GameTest_testGameCompleteStrikeInTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testGameCompleteStrikeInTenth() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 62, "testGameCompleteStrikeInTenth" ) {}
 void runTest() { suite_GameTest.testGameCompleteStrikeInTenth(); }
} testDescription_suite_GameTest_testGameCompleteStrikeInTenth;

static class TestDescription_suite_GameTest_testScoreAllOnes : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testScoreAllOnes() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 76, "testScoreAllOnes" ) {}
 void runTest() { suite_GameTest.testScoreAllOnes(); }
} testDescription_suite_GameTest_testScoreAllOnes;

static class TestDescription_suite_GameTest_testSpare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testSpare() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 86, "testSpare" ) {}
 void runTest() { suite_GameTest.testSpare(); }
} testDescription_suite_GameTest_testSpare;

static class TestDescription_suite_GameTest_testStrikeAfterSpare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testStrikeAfterSpare() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 104, "testStrikeAfterSpare" ) {}
 void runTest() { suite_GameTest.testStrikeAfterSpare(); }
} testDescription_suite_GameTest_testStrikeAfterSpare;

static class TestDescription_suite_GameTest_testCaseFromAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testCaseFromAssignment() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 125, "testCaseFromAssignment" ) {}
 void runTest() { suite_GameTest.testCaseFromAssignment(); }
} testDescription_suite_GameTest_testCaseFromAssignment;

static class TestDescription_suite_GameTest_testSpareStrikeInTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testSpareStrikeInTenth() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 195, "testSpareStrikeInTenth" ) {}
 void runTest() { suite_GameTest.testSpareStrikeInTenth(); }
} testDescription_suite_GameTest_testSpareStrikeInTenth;

static class TestDescription_suite_GameTest_testStrikeInTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testStrikeInTenth() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 228, "testStrikeInTenth" ) {}
 void runTest() { suite_GameTest.testStrikeInTenth(); }
} testDescription_suite_GameTest_testStrikeInTenth;

static class TestDescription_suite_GameTest_testLotsOSparesNormalTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testLotsOSparesNormalTenth() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 261, "testLotsOSparesNormalTenth" ) {}
 void runTest() { suite_GameTest.testLotsOSparesNormalTenth(); }
} testDescription_suite_GameTest_testLotsOSparesNormalTenth;

static class TestDescription_suite_GameTest_testGutterAndThenOne : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testGutterAndThenOne() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 285, "testGutterAndThenOne" ) {}
 void runTest() { suite_GameTest.testGutterAndThenOne(); }
} testDescription_suite_GameTest_testGutterAndThenOne;

static class TestDescription_suite_GameTest_testPerfectGame : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameTest_testPerfectGame() : CxxTest::RealTestDescription( Tests_GameTest, suiteDescription_GameTest, 298, "testPerfectGame" ) {}
 void runTest() { suite_GameTest.testPerfectGame(); }
} testDescription_suite_GameTest_testPerfectGame;

#include "/Users/helmicmt/src/teaching/CS2/cs1022/solutions/hw05-bowling/GameRecTest.h"

static GameRecTest suite_GameRecTest;

static CxxTest::List Tests_GameRecTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_GameRecTest( "GameRecTest.h", 13, "GameRecTest", suite_GameRecTest, Tests_GameRecTest );

static class TestDescription_suite_GameRecTest_testWeirdGame : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testWeirdGame() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 36, "testWeirdGame" ) {}
 void runTest() { suite_GameRecTest.testWeirdGame(); }
} testDescription_suite_GameRecTest_testWeirdGame;

static class TestDescription_suite_GameRecTest_testGameCompleteCorrectly : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testGameCompleteCorrectly() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 54, "testGameCompleteCorrectly" ) {}
 void runTest() { suite_GameRecTest.testGameCompleteCorrectly(); }
} testDescription_suite_GameRecTest_testGameCompleteCorrectly;

static class TestDescription_suite_GameRecTest_testGameCompleteStrikeInTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testGameCompleteStrikeInTenth() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 62, "testGameCompleteStrikeInTenth" ) {}
 void runTest() { suite_GameRecTest.testGameCompleteStrikeInTenth(); }
} testDescription_suite_GameRecTest_testGameCompleteStrikeInTenth;

static class TestDescription_suite_GameRecTest_testScoreAllOnes : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testScoreAllOnes() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 76, "testScoreAllOnes" ) {}
 void runTest() { suite_GameRecTest.testScoreAllOnes(); }
} testDescription_suite_GameRecTest_testScoreAllOnes;

static class TestDescription_suite_GameRecTest_testSpare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testSpare() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 86, "testSpare" ) {}
 void runTest() { suite_GameRecTest.testSpare(); }
} testDescription_suite_GameRecTest_testSpare;

static class TestDescription_suite_GameRecTest_testStrikeAfterSpare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testStrikeAfterSpare() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 104, "testStrikeAfterSpare" ) {}
 void runTest() { suite_GameRecTest.testStrikeAfterSpare(); }
} testDescription_suite_GameRecTest_testStrikeAfterSpare;

static class TestDescription_suite_GameRecTest_testCaseFromAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testCaseFromAssignment() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 125, "testCaseFromAssignment" ) {}
 void runTest() { suite_GameRecTest.testCaseFromAssignment(); }
} testDescription_suite_GameRecTest_testCaseFromAssignment;

static class TestDescription_suite_GameRecTest_testSpareStrikeInTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testSpareStrikeInTenth() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 195, "testSpareStrikeInTenth" ) {}
 void runTest() { suite_GameRecTest.testSpareStrikeInTenth(); }
} testDescription_suite_GameRecTest_testSpareStrikeInTenth;

static class TestDescription_suite_GameRecTest_testStrikeInTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testStrikeInTenth() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 228, "testStrikeInTenth" ) {}
 void runTest() { suite_GameRecTest.testStrikeInTenth(); }
} testDescription_suite_GameRecTest_testStrikeInTenth;

static class TestDescription_suite_GameRecTest_testLotsOSparesNormalTenth : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testLotsOSparesNormalTenth() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 261, "testLotsOSparesNormalTenth" ) {}
 void runTest() { suite_GameRecTest.testLotsOSparesNormalTenth(); }
} testDescription_suite_GameRecTest_testLotsOSparesNormalTenth;

static class TestDescription_suite_GameRecTest_testGutterAndThenOne : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testGutterAndThenOne() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 285, "testGutterAndThenOne" ) {}
 void runTest() { suite_GameRecTest.testGutterAndThenOne(); }
} testDescription_suite_GameRecTest_testGutterAndThenOne;

static class TestDescription_suite_GameRecTest_testPerfectGame : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameRecTest_testPerfectGame() : CxxTest::RealTestDescription( Tests_GameRecTest, suiteDescription_GameRecTest, 298, "testPerfectGame" ) {}
 void runTest() { suite_GameRecTest.testPerfectGame(); }
} testDescription_suite_GameRecTest_testPerfectGame;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
