#ifndef FIBONACCI_TEST_H
#define FIBONACCI_TEST_H

#include <fibonacci.h>

#include <cxxtest/TestSuite.h>

class FibonacciTest : public CxxTest::TestSuite {
public:
  void testFib0() {
    Fibonacci f;
    TS_ASSERT_EQUALS(0, f.getFib(0));
    vector<unsigned long> calls = f.getCallCount();
    TS_ASSERT_EQUALS(1, calls.size());
    TS_ASSERT_EQUALS(1, calls[0]);
  }

  void testFib1() {
    Fibonacci f;
    TS_ASSERT_EQUALS(1, f.getFib(1));
    vector<unsigned long> calls = f.getCallCount();
    TS_ASSERT_EQUALS(2, calls.size());
    TS_ASSERT_EQUALS(0, calls[0]);
    TS_ASSERT_EQUALS(1, calls[1]);
  }

  void testFib2() {
    Fibonacci f;
    TS_ASSERT_EQUALS(1, f.getFib(2));
    vector<unsigned long> calls = f.getCallCount();
    TS_ASSERT_EQUALS(3, calls.size());
    TS_ASSERT_EQUALS(1, calls[0]);
    TS_ASSERT_EQUALS(1, calls[1]);
    TS_ASSERT_EQUALS(1, calls[1]);
  }

  void testFib3() {
    Fibonacci f;
    TS_ASSERT_EQUALS(2, f.getFib(3));

  }
};

#endif