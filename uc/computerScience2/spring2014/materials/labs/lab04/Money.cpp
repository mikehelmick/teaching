#include <string>
#include <sstream>

#include <Money.h>
using namespace std;

Money::Money() {
  dollars = 0;
  cents = 0;
}

Money::Money(unsigned int dollars, unsigned int cents) {
  this->dollars = dollars;
  this->cents = cents;
}

Money::Money(double amount) {
  // convert this to dollars and cents.
  dollars = (int) amount;
  cents = (int) ((amount - dollars)*100);
}
  
void Money::add(const Money& amount) {
  // Add the amount from the other object into this one.
  dollars += amount.dollars;
  cents += amount.cents;
}

void Money::subtract(const Money& amount) {
  // Subtract the other amount from this object
  if (amount.cents > cents) {
    // We need to do a borrow, convert one of our dollars into cents.
    cents += 100;
    dollars--;
  }
  // Now just do the subtraction
  dollars - amount.dollars;
  cents - amount.cents;
}

void Money::acrueInterest(double apr, int periodsPerYear) {
  // calculate interest for the period.
  double monthlyRate = apr / periodsPerYear;
  double asDouble = getAsDouble();
  double interestAmount = asDouble * monthlyRate;
  double newAmount = asDouble + interestAmount;
  // Hmmm, This needs to get converted back into dollars and cents.
  // I'm not sure how to do that, I will come back to this later.
}

double Money::getAsDouble() const {
  return (double)dollars + cents/100;
}

unsigned int Money::getDollars() const {
  return dollars;
}
  
unsigned int Money::getCents() const {
  return cents;
}

string Money::toString() const {
  stringstream ss;
  ss << "$" << dollars << "." << cents;
  return ss.str();
}
