#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H

#include "Queue.h"

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class QueueTest : public CxxTest::TestSuite {
public:
	
	// Constructors
  void testME() {
    // Queue<float> l;  // Should be able to do this!
		Queue l;
		TS_ASSERT(l.size() == 0);
  }
	
	  
};

#endif