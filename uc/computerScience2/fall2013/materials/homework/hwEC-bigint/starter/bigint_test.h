#include "bigint.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class BigIntTest : public CxxTest::TestSuite {
public:

	// FILL IN MORE UNIT TESTS HERE
	
	// Example unit tests
  void testDefaultConstructorLong() {
    BigInt a;
    TS_ASSERT_EQUALS(0, a.getAsLong());
  }
	
  void testConstructorStringNeg() {
		try{
    	BigInt a = BigInt("-46");
		}catch(exception& e){
			return; // All ok if some exception was thrown.
		}
    TS_ASSERT(0);	// Bail if we got here since exception should have been thrown
  }
	
 

};
