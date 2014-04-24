// ex13 - Fraction.cpp
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

#include <Fraction.h>

using namespace std;

Fraction::Fraction() : numerator(1), denominator(1) {
}

Fraction::Fraction(int numerator, int denominator)
  : numerator(numerator), denominator(denominator) {
  reduce();
}

Fraction::Fraction(Fraction &that)
    : numerator(that.numerator), denominator(that.denominator) {
  reduce();
}

Fraction::~Fraction() {
  // nothing to do
}

void Fraction::add(const Fraction &rhs) {
  if (numerator == 0) {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
  } else if (denominator == rhs.denominator) {
    // Easy case - same base, just add together
    numerator += rhs.numerator;
  } else {
    numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    denominator *= rhs.denominator;
  }
  reduce();
}

void Fraction::subtract(const Fraction &rhs) {
  if (numerator == 0 ) {
    numerator = -rhs.numerator;
    denominator = rhs.denominator;
  } else if (denominator == rhs.denominator) {
    // Easy case - same base, just add together
    numerator -= rhs.numerator;
  } else {
    numerator = numerator * rhs.denominator - denominator * rhs.numerator;
    denominator *= rhs.denominator;
  }
  reduce();
}

void Fraction::multiply(const Fraction &rhs) {
  numerator *= rhs.numerator;
  denominator *= rhs.denominator;
  reduce();
}

void Fraction::divide(const Fraction &rhs) {
  // Multiply through by the reciprocal...
  numerator *= rhs.denominator;
  denominator *= rhs.numerator;
  reduce();
}

string Fraction::toString() const {
  stringstream ss;
  ss << numerator << "/" << denominator;
  
  string s = ss.str();
  return s;
}

int Fraction::getNumerator() const {
  return numerator;
}

int Fraction::getDenominator() const {
  return denominator;
}
  
void Fraction::reduce() {
  if (numerator == 0 || denominator == 0) {
    numerator = 0;
    denominator = 0;
    return;
  }
  int divBy = gcd(abs(numerator), abs(denominator));
  numerator = (numerator / divBy);
  denominator = (denominator / divBy);
}

int Fraction::gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}