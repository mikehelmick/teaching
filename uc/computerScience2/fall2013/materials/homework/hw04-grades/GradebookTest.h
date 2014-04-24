#ifndef GRADEBOOK_TEST_H
#define GRADEBOOK_TEST_H

#include <Gradebook.h>

#include <cxxtest/TestSuite.h>

class GradebookTest : public CxxTest::TestSuite {
public:
  void testAddOne() {
    Gradebook gb;
    gb.addGrade(50);
    TS_ASSERT_EQUALS(1, gb.getSize());
    TS_ASSERT_DELTA(50, gb.getMean(), 0.001);
  }
  
  void testAddMultiple() {
    Gradebook gb;
    gb.addGrade(75);
    TS_ASSERT_EQUALS(1, gb.getSize());
    gb.addGrade(85);
    TS_ASSERT_EQUALS(2, gb.getSize());
    TS_ASSERT_DELTA(80, gb.getMean(), 0.001);
  }

  void testAddALot() {
    Gradebook gb;
    for (int i = 0; i < 20000; i++) {
      gb.addGrade(90);
    }
    for (int i = 0; i < 20000; i++) {
      gb.addGrade(100);
    }
    TS_ASSERT_EQUALS(40000, gb.getSize());
    TS_ASSERT_DELTA(95, gb.getMean(), 0.001);
  }

  void testStdDev() {
    Gradebook gb;
    gb.addGrade(90);
    gb.addGrade(92);
    gb.addGrade(94);
    TS_ASSERT_EQUALS(3, gb.getSize());
    TS_ASSERT_DELTA(92.0, gb.getMean(), 0.001);
    TS_ASSERT_DELTA(1.63299, gb.getStandardDeviation(), 0.01);
  }
};

#endif
