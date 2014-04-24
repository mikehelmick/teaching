#include "bigint.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class BigIntTest : public CxxTest::TestSuite {
public:
// Constructors
  void testDefaultConstructorLong() {
    BigInt a;
    TS_ASSERT_EQUALS(0, a.getAsLong());
  }

  void testDefaultConstructorString() {
    BigInt a;
    TS_ASSERT_EQUALS("0", a.getAsDigits());
  }
  
  void testLongConstructorLong() {
    BigInt a = BigInt(45);
    TS_ASSERT_EQUALS(45, a.getAsLong());
  }

  void testLongtConstructorString() {
    BigInt a = BigInt(46);
    TS_ASSERT_EQUALS("46", a.getAsDigits());
  }
  
// String to BigInt
  void testConstructorString1() {
    BigInt a = BigInt("46");
    TS_ASSERT_EQUALS(46, a.getAsLong());
  }
	
  void testConstructorString2() {
    BigInt a = BigInt("0");
    TS_ASSERT_EQUALS(0, a.getAsLong());
  }
	
  void testConstructorString3() {	// larger than block size!
    BigInt a = BigInt("2000");
    TS_ASSERT_EQUALS(2000, a.getAsLong());
  }
	
  void testConstructorString4() {	// larger than block size!
    BigInt a = BigInt("2000000");
    TS_ASSERT_EQUALS(2000000, a.getAsLong());
  }
	
  void testConstructorStringNeg() {
		try{
    	BigInt a = BigInt("-46");
		}catch(exception& e){
			return; // All ok if some exception was thrown.
		}
    TS_ASSERT(0);	// Bail if we got here since exception should have been thrown
  }
	
  void testgetAsLongException() { // Adds values to trigger an exception in getAsLong
		int i = 0;
		try{
    	BigInt a = BigInt(100000);
			for(i = 0; i < 55; i++){
				a.add(a);
				unsigned long result = 0;
				result = result + a.getAsLong();
			}
		}catch(exception& e){
			return; // All ok if some exception was thrown.
		}
    TS_ASSERT(0);	// Bail if we got here since exception should have been thrown
  }
  
// Equality
  void testEquality1() {
    BigInt a = BigInt(46);
    BigInt b = BigInt(46);
    TS_ASSERT_EQUALS(a.isEqual(b), true);
  }
  void testEquality2() {
    BigInt a = BigInt(46);
    BigInt b = BigInt(5);
    TS_ASSERT_EQUALS(a.isEqual(b), false);
  }
  void testEquality3() {
    BigInt a = BigInt(0);
    BigInt b = BigInt(0);
    TS_ASSERT_EQUALS(a.isEqual(b), true);
  }
  void testEquality4() {
    BigInt a = BigInt("451");
    BigInt b = BigInt("45");
    TS_ASSERT_EQUALS(a.isEqual(b), false);
  }
  void testEquality5() {
    BigInt a = BigInt("45");
    BigInt b = BigInt("45");
    TS_ASSERT_EQUALS(a.isEqual(b), true);
  }
	
  void testEquality6() {
    BigInt a = BigInt("450000");
    BigInt b = BigInt("45");
    TS_ASSERT_EQUALS(a.isEqual(b), false);
  }
	
  void testEquality7() {
    BigInt a = BigInt("45");
    BigInt b = BigInt("450000");
    TS_ASSERT_EQUALS(a.isEqual(b), false);
  }
	
  void testEquality8() {
    BigInt a = BigInt("45000");
    BigInt b = BigInt("45000");
    TS_ASSERT_EQUALS(a.isEqual(b), true);
  }
	
// Subtraction
	void testSub1(){
    BigInt a = BigInt(46);
    BigInt b = BigInt(46);
		a.subtract(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 0);
		TS_ASSERT_EQUALS(b.getAsLong(), 46);
	}
	
	void testSub2(){
    BigInt a = BigInt(46);
    BigInt b = BigInt(0);
		a.subtract(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 46);
	}
	
	void testSub3(){
    BigInt a = BigInt(46);
    BigInt b = BigInt(48);
		try{
			a.subtract(b);
    }catch(exception& e){
    	return; 	// All ok if some exception was thrown.
    }
		TS_ASSERT(0);	// Bail if we got here since exception should have been thrown
	}
	
	void testSub4(){
    BigInt a = BigInt(46);
    BigInt b = BigInt(40);
		a.subtract(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 6);
	}
	
	void testSub5(){
    BigInt a = BigInt(1001);
    BigInt b = BigInt(1);
		a.subtract(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 1000);
	}
	
	void testSub6(){
    BigInt a = BigInt(5001);
    BigInt b = BigInt(100);
		a.subtract(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 5001-100);
	}
	
// Addition
	void testAdd1(){
    BigInt a = BigInt(46);
    BigInt b = BigInt(0);
		a.add(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 46);
		TS_ASSERT_EQUALS(b.getAsLong(), 0);
	}
	
	void testAdd2(){
    BigInt a = BigInt(0);
    BigInt b = BigInt(46);
		a.add(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 46);
		TS_ASSERT_EQUALS(b.getAsLong(), 46);
	}
	
	void testAdd3(){
    BigInt a = BigInt(46);
    BigInt b = BigInt(46);
		a.add(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 46+46);
		TS_ASSERT_EQUALS(b.getAsLong(), 46);
	}
	
	void testAdd4(){
    BigInt a = BigInt(900);
    BigInt b = BigInt(100);
		a.add(b);	// Should fit in one block
    TS_ASSERT_EQUALS(a.getAsLong(), 900+100);
		TS_ASSERT_EQUALS(b.getAsLong(), 100);
	}
	
	void testAdd5(){
    BigInt a = BigInt(901);
    BigInt b = BigInt(100);
		a.add(b);	// Should need 2 blocks
    TS_ASSERT_EQUALS(a.getAsLong(), 901+100);
		TS_ASSERT_EQUALS(b.getAsLong(), 100);
	}
	
	void testAdd6(){
    BigInt a = BigInt(101);
    BigInt b = BigInt(900);
		a.add(b);	// Should need 2 blocks
    TS_ASSERT_EQUALS(a.getAsLong(), 901+100);
		TS_ASSERT_EQUALS(b.getAsLong(), 900);
	}
	
	void testAdd7(){
    BigInt a = BigInt(999);
    BigInt b = BigInt(999);
		a.add(b);	// Should need 2 blocks
		a.add(b);
		a.add(b);
    TS_ASSERT_EQUALS(a.getAsLong(), 999 * 4);
		TS_ASSERT_EQUALS(b.getAsLong(), 999);
	}
	

};
