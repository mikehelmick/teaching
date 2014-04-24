#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
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

Fraction::Fraction(const Fraction &that)
    : numerator(that.numerator), denominator(that.denominator) {
}

Fraction::~Fraction() {
  // nothing to do
}

Fraction& Fraction::operator=(const Fraction& rhs) {
  this->numerator = rhs.numerator;
  this->denominator = rhs.denominator;
  return *this;
}

Fraction Fraction::operator+(const Fraction &rhs) {
  Fraction tmp(*this); 

  if (tmp.numerator == 0) {
    tmp.numerator = rhs.numerator;
    tmp.denominator = rhs.denominator;
  } else if (denominator == rhs.denominator) {
    tmp.numerator += rhs.numerator;
  } else {
    tmp.numerator = this->numerator * rhs.denominator
        + this->denominator * rhs.numerator;
    tmp.denominator *= rhs.denominator;
  }

  tmp.reduce();
  return tmp;
}

Fraction Fraction::operator-(const Fraction &rhs) {
  Fraction tmp(*this);

  if (tmp.numerator == 0) {
    tmp.numerator = -rhs.numerator;
    tmp.denominator = rhs.denominator;
  } else if (tmp.denominator == rhs.denominator) {
    tmp.numerator -= rhs.numerator;
  } else {
    tmp.numerator = numerator * rhs.denominator
        - denominator * rhs.numerator;
    tmp.denominator *= rhs.denominator;
  }

  tmp.reduce();
  return tmp;
}

Fraction Fraction::operator*(const Fraction &rhs) {
  Fraction tmp(*this);
  tmp.numerator *= rhs.numerator;
  tmp.denominator *= rhs.denominator;
  tmp.reduce();
  return tmp;
}

Fraction Fraction::operator/(const Fraction &rhs) {
  Fraction tmp(*this);
  tmp.numerator *= rhs.denominator;
  tmp.denominator *= rhs.numerator;
  tmp.reduce();
  return tmp;
}

bool Fraction::operator<(const Fraction &rhs) {
  double a = this->numerator / (double)this->denominator;
  double b = rhs.numerator / (double)rhs.denominator;
  return a < b;
}

bool Fraction::operator>(const Fraction &rhs) {
  double a = this->numerator / (double)this->denominator;
  double b = rhs.numerator / (double)rhs.denominator;
  return a > b;
}

bool Fraction::operator==(const Fraction &rhs) {
  return this->numerator == rhs.numerator
      && this->denominator == rhs.denominator;
}

bool Fraction::operator!=(const Fraction &rhs) {
  return !(*this == rhs);
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
