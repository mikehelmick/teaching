#ifndef FRACTION_TEST_H
#define FRACTION_TEST_H

#include <iostream>
#include <cxxtest/TestSuite.h>

#include <Fraction.h>

using namespace std;

class FractionTest : public CxxTest::TestSuite {
public:
  
  void testToString() {
    Fraction a(192, 3);
    TS_ASSERT_EQUALS("64/1", a.toString());
  }
  
  void testToString2() {
    Fraction a(4, 5);
    TS_ASSERT_EQUALS("4/5", a.toString());
  }

  void testAddition() {
    Fraction a(1, 3);
    Fraction b(1, 3);
    
    a.add(b);
    TS_ASSERT_EQUALS(2, a.getNumerator());
    TS_ASSERT_EQUALS(3, a.getDenominator());
  }
  
  void testAdditionDifferentBase() {
    Fraction a(1, 3);
    Fraction b(1, 6);
    a.add(b);
    TS_ASSERT_EQUALS(1, a.getNumerator());
    TS_ASSERT_EQUALS(2, a.getDenominator());
  }

  void testSubtraction() {
    Fraction a(2, 3);
    Fraction b(1, 3);
    a.subtract(b);
    TS_ASSERT_EQUALS(1, a.getNumerator());
    TS_ASSERT_EQUALS(3, a.getDenominator());    
  }
  
  void testSubtractionNegative() {
    Fraction a(1, 3);
    Fraction b(2, 3);
    a.subtract(b);
    TS_ASSERT_EQUALS(-1, a.getNumerator());
    TS_ASSERT_EQUALS(3, a.getDenominator());       
  }
  
  void testSubtractionDifferentBase() {
    Fraction a(5, 6);
    Fraction b(1, 2);
    a.subtract(b);
    TS_ASSERT_EQUALS(1, a.getNumerator());
    TS_ASSERT_EQUALS(3, a.getDenominator());   
  }
  
  void testMultiplication() {
    Fraction a(1, 3);
    Fraction b(2, 3);
    a.multiply(b);
    TS_ASSERT_EQUALS(2, a.getNumerator());
    TS_ASSERT_EQUALS(9, a.getDenominator());       
  }
  
  void testMultiplication2() {
    Fraction a(2, 5);
    Fraction b(1, 2);
    a.multiply(b);
    TS_ASSERT_EQUALS(1, a.getNumerator());
    TS_ASSERT_EQUALS(5, a.getDenominator());       
  }

  void testDivision() {
    Fraction a(1, 2);
    Fraction b(1, 6);
    a.divide(b);
    TS_ASSERT_EQUALS(3, a.getNumerator());
    TS_ASSERT_EQUALS(1, a.getDenominator());
  }

  void testDivision2() {
    Fraction a(8, 9);
    Fraction b(2, 3);
    a.divide(b);
    TS_ASSERT_EQUALS(4, a.getNumerator());
    TS_ASSERT_EQUALS(3, a.getDenominator());
  }
  
  void testZeroAddition() {
    Fraction a(0, 0);
    Fraction b(1, 1);
    a.add(b);
    TS_ASSERT_EQUALS(1, a.getNumerator());
    TS_ASSERT_EQUALS(1, a.getDenominator());   
  }
  
  void testZeroSubtraction() {
    Fraction a(0, 0);
    Fraction b(1, 2);
    a.subtract(b);
    TS_ASSERT_EQUALS(-1, a.getNumerator());
    TS_ASSERT_EQUALS(2, a.getDenominator());
  }
};

#endif