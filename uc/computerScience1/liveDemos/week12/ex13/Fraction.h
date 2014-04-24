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
  Fraction(Fraction &that);

  virtual ~Fraction();

  // Adds the value of rhs to this, and changes this.
  void add(const Fraction &rhs);

  void subtract(const Fraction &rhs);

  void multiply(const Fraction &rhs);

  void divide(const Fraction &rhs);

  string toString() const;
  int getNumerator() const;
  int getDenominator() const;

private:
  int numerator;
  int denominator;

  void reduce();
  int gcd(int a, int b);
};

#endif
