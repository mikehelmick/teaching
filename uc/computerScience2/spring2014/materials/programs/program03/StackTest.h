#ifndef STACK_TEST_H
#define STACK_TEST_H

#include "Stack.h"

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class StackTest : public CxxTest::TestSuite {
public:
	
	// Constructors
  void testME() {
    //Stack<int> l;	// Should be able to do this!
		Stack l;
		TS_ASSERT(l.size() == 0);
  }
	
	  
};

#endif