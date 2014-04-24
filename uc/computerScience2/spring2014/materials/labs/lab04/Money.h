#ifndef MONEY_H
#define MONEY_H

#include <string>
using namespace std;

/**
 * Represents a sum of money. Has opertions for adding and
 * subtracting amounts as well as accuring interest.
 */
class Money {
public:
  // Default constructor, balance of 0.00
  Money();
  // Create with a specific amount of money.
  Money(unsigned int dollars, unsigned int cents);
  // Derive the amount of money from 
  Money(double amount);
  
  // Add the passed in amount to the current object.
  void add(const Money& amount);
  // Subtract the passed in amount from the current object.
  void subtract(const Money& amount);
  
  // Calculate 1 period of interest, based on the APR and the number
  // of periods per year, and add the interest to the amount.
  // 7% APR should be represented as 0.07
  void acrueInterest(double apr, int periodsPerYear);

  // Returns the amount of money as a double.
  double getAsDouble() const;
  // Returns the number of dolla.
  unsigned int getDollars() const;
  // Returns the number of cents.
  unsigned int getCents() const;
  // Returns a string representation, i.e. $5.10
  // Always shows 2 decimal places.
  string toString() const;
  
private:
  unsigned int dollars;
  unsigned int cents;
};

#endif
