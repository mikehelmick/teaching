#ifndef MONEY_TEST_H
#define MONEY_TEST_H

#include <Money.h>

#include <iostream>
#include <string>
#include <cxxtest/TestSuite.h>

using namespace std;

class MoneyTest : public CxxTest::TestSuite {
public:
  // Remember, test methods should be public, void, and start with
  // the word "test"
  void testGetAsDouble() {
    // You probably want to create an instance of the Money class
    Money myMoney(1, 23);
    // And test 
    TS_ASSERT_DELTA(1.23, myMoney.getAsDouble(), 0.0000001);
  }
  
};

#endif