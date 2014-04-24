#ifndef FRACTION_H
#define FRACTION_H

#include <string>
using namespace std;

class Fraction {
public:
  // Default constructor, sets to 1/1
  Fraction();
  // Whole number constructor, x/1
  Fraction(int numerator);
  // Fully qualified fraction num/denom
  Fraction(int numerator, int denominator);

  // Copy constructor!
  Fraction(const Fraction &that);

  virtual ~Fraction();

  Fraction& operator=(const Fraction &rhs);
  Fraction operator+(const Fraction &rhs);
  Fraction operator-(const Fraction &rhs);
  Fraction operator*(const Fraction &rhs);
  Fraction operator/(const Fraction &rhs);
  bool operator<(const Fraction &rhs);
  bool operator>(const Fraction &rhs);
  bool operator==(const Fraction &rhs);
  bool operator!=(const Fraction &rhs);

  string toString() const;
  int getNumerator() const;
  int getDenominator() const;

private:
  int numerator;
  int denominator;

  void reduce();
  static int gcd(int a, int b);
};

#endif
