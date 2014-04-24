#ifndef LIST_TEST_H
#define LIST_TEST_H

#include "List.h"

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class ListTest : public CxxTest::TestSuite {
public:
	
	// Constructors
  void testME() {
    //List<string> l;	// Should be able to do this!
		List l;
		TS_ASSERT(l.size() == 0);
  }
	
	  
};

#endif