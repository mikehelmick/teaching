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

  void testCompareTo1() {
    BigInt a(-50);
    BigInt b(-4);
    TS_ASSERT_LESS_THAN(a.compareTo(b), 0);
    TS_ASSERT_LESS_THAN(-1 * b.compareTo(a), 0);
  }

  void testCompareTo2() {
    BigInt a(-6);
    BigInt b(-4);
    TS_ASSERT_LESS_THAN(a.compareTo(b), 0);
    TS_ASSERT_LESS_THAN(-1 * b.compareTo(a), 0);
  }

  void testCompareTo3() {
    BigInt a(-6);
    BigInt b(10);
    TS_ASSERT_LESS_THAN(a.compareTo(b), 0);
    TS_ASSERT_LESS_THAN(-1 * b.compareTo(a), 0);
  }

  void testCompareTo4() {
    BigInt a(-6);
    BigInt b(-6);
    TS_ASSERT_EQUALS(a.compareTo(b), 0);
  }

  void testCompareTo5() {
    BigInt a(0);
    BigInt b(0);
    TS_ASSERT_EQUALS(a.compareTo(b), 0);
  }

  void testCompareTo6() {
    BigInt a(60);
    BigInt b(60);
    TS_ASSERT_EQUALS(a.compareTo(b), 0);
  }

  void testCompareTo7() {
    BigInt a(4);
    BigInt b(50);
    TS_ASSERT_LESS_THAN(a.compareTo(b), 0);
    TS_ASSERT_LESS_THAN(-1 * b.compareTo(a), 0);
  }

  void testCompareTo8() {
    BigInt a("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    BigInt b("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567891");
    TS_ASSERT_LESS_THAN(a.compareTo(b), 0);
    TS_ASSERT_LESS_THAN(-1 * b.compareTo(a), 0);
  }

  void testAdd1() {
    BigInt a("0");
    BigInt b("5");
    a.add(b);
    TS_ASSERT_EQUALS(a.getAsDigits(), "5");
  }

  void testAdd2() {
    BigInt a("11");
    BigInt b("9999");
    a.add(b);
    TS_ASSERT_EQUALS(a.getAsDigits(), "10010");
  }

  void testAdd3() {
    BigInt a("25");
    BigInt b("1812309213049812347");
    a.add(b);
    TS_ASSERT_EQUALS(a.getAsDigits(), "1812309213049812372");
  }

  void testAdd4() {
    BigInt b("25");
    BigInt a("1812309213049812347");
    a.add(b);
    TS_ASSERT_EQUALS(a.getAsDigits(), "1812309213049812372");
  }
  
  void testAdd5() {
    BigInt a("-25");
    BigInt b("-1812309213049812347");
    a.add(b);
    TS_ASSERT_EQUALS(a.getAsDigits(), "-1812309213049812372");
  }

  void testAdd6() {
    BigInt b("-25");
    BigInt a("-1812309213049812347");
    a.add(b);
    TS_ASSERT_EQUALS(a.getAsDigits(), "-1812309213049812372");
  }

  void testAdd7() {
    
  }
};
