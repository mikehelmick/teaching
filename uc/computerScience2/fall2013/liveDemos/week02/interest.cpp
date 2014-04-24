#include <iostream>
using namespace std;

/**
 * Computes interest.
 * @param amt starting amount in dollars
 * @param rate the interest rate, i.e. 0.02 for 2%
 **/
double computeInterest(double amt, double rate) {
  return amt * (1.0 + rate); 
}

double compoundInterest(double amt, double rate, int periodsPerYear, int periods) {
  if (periods <= 0) {
    cerr << "Unable to compute interest for 0 or less periods." << endl;
    return amt;
  }

  double periodRate = rate / periodsPerYear;
  for (int i = 0; i < periods; i++) {
    amt = computeInterest(amt, periodRate);
  }
  return amt;
}

int main() {
  double starting = 100.0;

  for (int months = 1; months <= 24; months++) {
    double ending = compoundInterest(starting, 0.0075, 12, months);
    cout << "$" << starting << " becomes " << ending << " after " << months << " months at an APR of 0.75%" << endl;
  }

  return 0;
}
