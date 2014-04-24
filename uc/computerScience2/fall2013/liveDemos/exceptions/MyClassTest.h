#include "MyClass.h"


#include <cxxtest/TestSuite.h>
#include <stdexcept>
#include <iostream>
using namespace std;

class MyClassTest : public CxxTest::TestSuite {
public:
  void testGood() {
	  MyClass c;
    TS_ASSERT(c.isValid(2));
  }
  
  void testBad() {
    MyClass c;
    try {
      c.isValid(3);
      TS_FAIL("Expected exception was not thrown");
    } catch (invalid_argument& iae) {
      // Success! Threw an exception when it should
    }
  }
};
