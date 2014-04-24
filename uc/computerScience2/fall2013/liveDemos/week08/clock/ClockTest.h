/*
 * Clock_test.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#include "Clock.h"

#include <cxxtest/TestSuite.h>

#include <iostream>
using namespace std;

class ClockTest : public CxxTest::TestSuite {
public:
  void testClockConstructor() {
	  cout << endl << "testClockConstructor" << endl;
	  Clock clock;
  }
};
