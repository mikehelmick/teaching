#include "bigint.h"

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
  
  // TODO: string to bigint
  
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
    BigInt a = BigInt(-45);
    BigInt b = BigInt(45);
    TS_ASSERT_EQUALS(a.isEqual(b), false);
  }
  void testEquality5() {
    BigInt a = BigInt(-45);
    BigInt b = BigInt(-45);
    TS_ASSERT_EQUALS(a.isEqual(b), true);
  }
  
// Comparison
  void testLess1() {
    BigInt a = BigInt(46);
    BigInt b = BigInt(5);
    TS_ASSERT_EQUALS(a.isLess(b), false);
  }
  void testLess2() {
    BigInt a = BigInt(46);
    BigInt b = BigInt(5);
    TS_ASSERT_EQUALS(b.isLess(a), true);
  }
  void testLess3() {
    BigInt a = BigInt(46);
    a.add(BigInt(3456));
    BigInt b = BigInt(5);
    TS_ASSERT_EQUALS(b.isLess(a), true);
  }
  void testLess4() {
    BigInt a = BigInt(46);
    a.add(BigInt(3456));
    BigInt b = BigInt(5);
    b.add(BigInt(3456));
    TS_ASSERT_EQUALS(b.isLess(a), true);
  }
  void testLess5() {
    BigInt a = BigInt(-46);
    BigInt b = BigInt(-5);
    TS_ASSERT_EQUALS(a.isLess(b), true);
  }
  void testLess6() {
    BigInt a = BigInt(-46);
    BigInt b = BigInt(-5);
    TS_ASSERT_EQUALS(b.isLess(a), false);
  }
  void testLess7() {
    BigInt a = BigInt(-46);
    a.add(BigInt(-3456));
    BigInt b = BigInt(-5);
    TS_ASSERT_EQUALS(b.isLess(a), false);
  }
  void testLess8() {
    BigInt a = BigInt(-46);
    a.add(BigInt(-3456));
    BigInt b = BigInt(-5);
    b.add(BigInt(-3456));
    TS_ASSERT_EQUALS(b.isLess(a), false);
  }

};
