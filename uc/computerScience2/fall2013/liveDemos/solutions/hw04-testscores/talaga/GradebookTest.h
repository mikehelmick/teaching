/**   @file GradebookTest.h    
      @author Paul Talaga
      @date 10-11-2013
      
      Unit tests for the gradebook.
      */

#ifndef GRADEBOOK_TEST_H
#define GRADEBOOK_TEST_H

#include <Gradebook.h>

#include <cxxtest/TestSuite.h>

class GradebookTest : public CxxTest::TestSuite {
public:

  /*********************************************/
  
    // Default constructor tested in almost ALL
    // other tests!

  /*********************************************/
  
  void testConstructorFile(){
    // assume grades.txt is in folder!!!
    Gradebook gb("grades.txt");
    TS_ASSERT_LESS_THAN(0, gb.getCount());
  }

  /*********************************************/
  
  void testCopyConstructor(){
    Gradebook gb;
    gb.addScore(50);
    Gradebook gb2(gb);
    gb.addScore(50);
    TS_ASSERT_EQUALS(2, gb.getCount());
    TS_ASSERT_EQUALS(1, gb2.getCount());
  }

  /*********************************************/
  
  void testAddOne() {
    Gradebook gb;
    gb.addScore(50);
    TS_ASSERT_EQUALS(1, gb.getCount());
    TS_ASSERT_DELTA(50, gb.getMean(), 0.001);
  }
  
  void testAddMultiple() {
    Gradebook gb;
    gb.addScore(75);
    TS_ASSERT_EQUALS(1, gb.getCount());
    gb.addScore(85);
    TS_ASSERT_EQUALS(2, gb.getCount());
    TS_ASSERT_DELTA(80, gb.getMean(), 0.001);
  }

  void testAddCountLots() {
    Gradebook gb;
    for (int i = 0; i < 20000; i++) {
      gb.addScore(90);
    }
    for (int i = 0; i < 20000; i++) {
      gb.addScore(100);
    }
    TS_ASSERT_EQUALS(40000, gb.getCount());
    TS_ASSERT_DELTA(95, gb.getMean(), 0.001);
  }
  
  /*********************************************/
  
  void testScoreAtNone1(){
    Gradebook gb;
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(-1, gb.getScoreAt(0), 0.001);
  }
  
  void testScoreAtNone2(){
    Gradebook gb;
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(-1, gb.getScoreAt(-1), 0.001);
  }
  
  void testScoreAtNone3(){
    Gradebook gb;
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(-1, gb.getScoreAt(1), 0.001);
  }
  
  void testScoreAtSingle1(){
    Gradebook gb;
    gb.addScore(55.5);
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(55.5, gb.getScoreAt(0), 0.001);
  }
  
  void testScoreAtSingle2(){
    Gradebook gb;
    gb.addScore(55.5);
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(55.5, gb.getScoreAt(0), 0.001);
  }
  
  void testScoreAtSingle31(){
    Gradebook gb;
    gb.addScore(55.5);
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(-1, gb.getScoreAt(1), 0.001);
  }
  
  void testScoreAtThree1(){
    Gradebook gb;
    gb.addScore(55.5);
    gb.addScore(65.5);
    gb.addScore(75.5);
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(55.5, gb.getScoreAt(0), 0.001);
  }
  
  void testScoreAtThree2(){
    Gradebook gb;
    gb.addScore(55.5);
    gb.addScore(65.5);
    gb.addScore(75.5);
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(75.5, gb.getScoreAt(2), 0.001);
  }
  
  void testScoreAtMedian(){
    // Makes sure getMedian doesn't change the order
    Gradebook gb;
    gb.addScore(55.5);
    gb.addScore(65.5);
    gb.addScore(75.5);
    gb.addScore(85.5);
    gb.addScore(95.5);
    gb.addScore(15.5);
    gb.addScore(25.5);
    gb.addScore(35.5);
    gb.addScore(45.5);
    TS_ASSERT_DELTA(55.5, gb.getMedian(), 0.001);
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(15.5, gb.getScoreAt(5), 0.001);
  }
  
  /*********************************************/
  
  void testFileNone(){
    Gradebook gb;
    TS_ASSERT_EQUALS("", gb.getSourceFile());
  }
  
  void testFileGiven(){
    const string fname = "grades.txt";
    Gradebook gb(fname);
    TS_ASSERT_EQUALS(fname, gb.getSourceFile());
  }
  
  /*********************************************/
  
  void testMeanNone(){
    Gradebook gb;
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(-1, gb.getMean(), 0.001);
  }
  
  void testMeanSingle(){
    Gradebook gb;
    gb.addScore(78.4);
    TS_ASSERT_DELTA(78.4, gb.getMean(), 0.001);
  }
  
  void testMeanTwo(){
    Gradebook gb;
    gb.addScore(78.4);
    gb.addScore(55.6);
    TS_ASSERT_DELTA(67.0, gb.getMean(), 0.001);
  }
  
  void testMeanLots(){
    Gradebook gb;
    for (int i = 1; i < 1000; i++) {
      gb.addScore(i * 0.1);
    }
    TS_ASSERT_DELTA(50, gb.getMean(), 0.001);
  }
  
  void testMeanLots2() {
    Gradebook gb;
    // Should base this on the central limit theorem to be spot on
    for (int i = 1; i < 100000; i++) {
      gb.addScore(static_cast<float>(rand()) / RAND_MAX * 100.0);
    }
    TS_ASSERT_DELTA(50.0, gb.getMean(), 0.1);
  }
  
  /*********************************************/
  
  void testMinNone(){
    Gradebook gb;
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(-1, gb.getMin(), 0.001);
  }
  
  void testMinOne(){
    Gradebook gb;
    gb.addScore(56.6);
    TS_ASSERT_DELTA(56.6, gb.getMin(), 0.001);
  }
  
  void testMinThree1(){
    Gradebook gb;
    gb.addScore(56.6);
    gb.addScore(96.6);
    gb.addScore(56.2);
    TS_ASSERT_DELTA(56.2, gb.getMin(), 0.001);
  }
  
  /*********************************************/
  
  void testMaxNone(){
    Gradebook gb;
    // Returns -1 if no grades entered
    TS_ASSERT_DELTA(-1, gb.getMax(), 0.001);
  }
  
  void testMaxOne(){
    Gradebook gb;
    gb.addScore(56.6);
    TS_ASSERT_DELTA(56.6, gb.getMax(), 0.001);
  }
  
  void testMaxThree(){
    Gradebook gb;
    gb.addScore(56.6);
    gb.addScore(96.6);
    gb.addScore(56.2);
    TS_ASSERT_DELTA(96.6, gb.getMax(), 0.001);
  }
  
  /*********************************************/
  
  void testMedianNone(){
    Gradebook gb;
    TS_ASSERT_DELTA(-1, gb.getMedian(), 0.01);
  }
  
  void testMedianOne(){
    Gradebook gb;
    gb.addScore(34.5);
    TS_ASSERT_DELTA(34.5, gb.getMedian(), 0.01);
  }
  
  void testMedianAddOrder1(){
    Gradebook gb;
    gb.addScore(34.5);
    gb.addScore(24.5);
    gb.addScore(64.5);
    gb.addScore(74.5);
    gb.addScore(44.5);
    TS_ASSERT_DELTA(44.5, gb.getMedian(), 0.01);
  }
  
  void testMedianAddOrder2(){
    Gradebook gb;
    gb.addScore(74.5);
    gb.addScore(44.5);
    gb.addScore(34.5);
    gb.addScore(24.5);
    gb.addScore(64.5);
    TS_ASSERT_DELTA(44.5, gb.getMedian(), 0.01);
  }
  
  void testMedianAddOrder3(){
    Gradebook gb;
    gb.addScore(44.5);
    gb.addScore(34.5);
    gb.addScore(24.5);
    gb.addScore(64.5);
    gb.addScore(74.5);
    TS_ASSERT_DELTA(44.5, gb.getMedian(), 0.01);
  }
  
  void testMedianEven(){
    Gradebook gb;
    gb.addScore(44.5);
    gb.addScore(34.5);
    gb.addScore(24.5);
    gb.addScore(64.5);
    // We set the median of an even cardinality set to
    // be the upper of the two middle values
    TS_ASSERT_DELTA(44.5, gb.getMedian(), 0.01);
  }
  
  void testMedianLots(){
    Gradebook gb;
    for (int i = 1; i < 10000; i++) {
      gb.addScore(static_cast<double>(i) / 10000 * 100.0);
    }
    // We set the median of an even cardinality set to
    // be the upper of the two middle values
    TS_ASSERT_DELTA(50.0, gb.getMedian(), 0.01);
  }
  
  /*********************************************/

  void testStdDevNone() {
    Gradebook gb;
    TS_ASSERT_DELTA(-1, gb.getStdDev(), 0.01);
  }
  
  void testStdDevOne() {
    Gradebook gb;
    gb.addScore(34.6);
    TS_ASSERT_DELTA(0, gb.getStdDev(), 0.01);
  }

  void testStdDevThree() {
    Gradebook gb;
    gb.addScore(90);
    gb.addScore(92);
    gb.addScore(94);
    TS_ASSERT_DELTA(1.63299, gb.getStdDev(), 0.01);
  }
  
  void testStdDevLots() {
    Gradebook gb;
    // See http://en.wikipedia.org/wiki/Uniform_distribution_(continuous)
    // Std should be 100/ sqrt(12)
    for (int i = 1; i < 10000; i++) {
      gb.addScore(static_cast<double>(rand()) / RAND_MAX * 100.0);
    }
    TS_ASSERT_DELTA(28.86, gb.getStdDev(), 0.1);
  }
  
  /*********************************************/
  
  void testRangeNone(){
    Gradebook gb;
    TS_ASSERT_EQUALS(0, gb.scoresInRange(5,6) );
  }
  
  void testRangeOneBelow(){
    Gradebook gb;
    gb.addScore(34.5);
    TS_ASSERT_EQUALS(0, gb.scoresInRange(0,30) );
  }
  
    void testRangeOneAbove(){
    Gradebook gb;
    gb.addScore(34.5);
    TS_ASSERT_EQUALS(0, gb.scoresInRange(35,60) );
  }
  
    void testRangeOneSpan(){
    Gradebook gb;
    gb.addScore(34.5);
    TS_ASSERT_EQUALS(1, gb.scoresInRange(30,60) );
  }
  
  void testRange1(){
    Gradebook gb;
    gb.addScore(34.5);
    gb.addScore(24.5);
    gb.addScore(64.5);
    gb.addScore(74.5);
    gb.addScore(44.5);
    TS_ASSERT_EQUALS(2, gb.scoresInRange(20,40) );
  }
  
  void testRangeBounds(){
    Gradebook gb;
    gb.addScore(74.5);
    gb.addScore(44.5);
    gb.addScore(34.5);
    gb.addScore(24.5);
    gb.addScore(64.5);
    TS_ASSERT_EQUALS(3, gb.scoresInRange(34.5,74.5) );
  }
  
  void testRangeBounds2(){
    Gradebook gb;
    gb.addScore(44.5);
    gb.addScore(34.5);
    gb.addScore(24.5);
    gb.addScore(64.5);
    gb.addScore(74.5);
    TS_ASSERT_EQUALS(4, gb.scoresInRange(34.5,74.6) );
  }
  
  
};

#endif
