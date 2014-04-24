// week13/ex11
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
  Fraction(const Fraction &that);

  // Destructor
  virtual ~Fraction();
 
  // Example: "1/2"
  string toString() const;
  // Returns the components
  int getNumerator() const;
  int getDenominator() const;

  Fraction& operator=(const Fraction &rhs);
  Fraction operator+(const Fraction &rhs);
  Fraction operator-(const Fraction &rhs);
  Fraction operator*(const Fraction &rhs);
  Fraction operator/(const Fraction &rhs);
  bool operator<(const Fraction &rhs);
  bool operator>(const Fraction &rhs);
  bool operator==(const Fraction &rhs);
  
private:
  int numerator;
  int denominator;
  
  // Redces / simplifies this fraction. This is done automatically after each
  // operation.
  void reduce();

  static int gcd(int a, int b);
};

#endif
