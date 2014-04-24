#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "List.h"

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class ListTest : public CxxTest::TestSuite {
public:
	
	// Constructors
  void testME() {
    List l();
		TS_ASSERT(l.size() == 0);
  }
	
	  
};

#endif