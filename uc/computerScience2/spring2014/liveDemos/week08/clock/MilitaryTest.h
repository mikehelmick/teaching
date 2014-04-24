
#include "Military.h"

#include <cxxtest/TestSuite.h>

class MilitaryTest : public CxxTest::TestSuite {
public:
  void testMilitaryClockConstructor() {
	  cout << endl << "testMilitaryClockConstructor" << endl;
	  Military clock;
  }
};
