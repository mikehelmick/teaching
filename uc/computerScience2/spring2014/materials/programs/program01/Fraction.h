#ifndef FRACTION_H
#define FRACTION_H

#include <string>
using namespace std;

class Fraction {
public:
  // Default consturctor, creates a fraction with the value of 1/1
  Fraction();
  // Creates a fraction with a custom numerator and denominator.
  // If necessary, the fraction is simplified for storage.
  Fraction(int numerator, int denominator);
  
  // Copy constructor, creates a copy of this fraction
  Fraction(Fraction &that);

  // Destructor
  virtual ~Fraction();

  // Adds the value of the passed in fraction to the current one.
  // The current fraction is then reduced.
  void add(const Fraction &rhs);
  
  // Subtracts the value of the passed in fraction to the current one.
  // The current fraction is then reduced.
  void subtract(const Fraction &rhs);
  
  // Multiplies this fraction agains the one passed in, modifying this one.
  // The current fraction is then reduced.
  void multiply(const Fraction &rhs);

  // Divited the current fraction by the one passed in, modifying this one.
  // The current fraction is then reduced.
  void divide(const Fraction &rhs);
  
  // Example: "1/2"
  string toString() const;
  // Returns the components
  int getNumerator() const;
  int getDenominator() const;
  
private:
  int numerator;
  int denominator;
  
  // Redces / simplifies this fraction. This is done automatically after each
  // operation.
  void reduce();

  static int gcd(int a, int b);
};

#endif
