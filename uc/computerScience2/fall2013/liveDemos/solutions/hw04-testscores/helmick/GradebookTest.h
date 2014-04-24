#ifndef GRADEBOOK_TEST_H
#define GRADEBOOK_TEST_H

#include <Gradebook.h>

#include <cxxtest/TestSuite.h>

class GradebookTest : public CxxTest::TestSuite {
public:
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

  void testAddALot() {
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

  void testStdDev() {
    Gradebook gb;
    gb.addScore(90);
    gb.addScore(92);
    gb.addScore(94);
    TS_ASSERT_EQUALS(3, gb.getCount());
    TS_ASSERT_DELTA(92.0, gb.getMean(), 0.001);
    TS_ASSERT_DELTA(1.63299, gb.getStdDev(), 0.01);
  }
};

#endif
