#include <string>
#include <sstream>
#include <cmath>
using namespace std;

#include <Fraction.h>

Fraction::Fraction()
    : numerator(1), denominator(1) {
}

Fraction::Fraction(int numerator)
    : numerator(numerator), denominator(1) {
}

Fraction::Fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {
}

Fraction::Fraction(Fraction &that)
    : numerator(that.numerator), denominator(that.denominator) {
}

Fraction::~Fraction() {
  // nothing to do
}

void Fraction::add(const Fraction &rhs) {
  if (numerator == 0) {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
  } else if (denominator == rhs.denominator) {
    numerator += rhs.numerator;
  } else {
    numerator = numerator * rhs.denominator
        + denominator + rhs.numerator;
    denominator *= rhs.denominator;
  }

  reduce();
}

void Fraction::subtract(const Fraction &rhs) {
  if (numerator == 0) {
    numerator = -rhs.numerator;
    denominator = rhs.denominator;
  } else if (denominator == rhs.denominator) {
    numerator -= rhs.numerator;
  } else {
    numerator = numerator * rhs.denominator
        - denominator * rhs.numerator;
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
  numerator /= divBy;
  denominator /= divBy;
}

int Fraction::gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}