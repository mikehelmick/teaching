
#include <iostream>
using namespace std;

double compute_interest(double amt, double rate) {
  return amt * (1.0 + rate);
}

/**
 * @periods_per_year interest rate, 0.01 represents 1 percent.
 */
double compound_interest(double amt, double rate, int periods_per_year, int periods) {
  if (periods <= 0) {
    cerr << "unable to compute compound interest unless periods is a positive number."
        << endl;
    return amt;
  }
	
  double period_rate = rate / periods_per_year;
  for (int i = 0; i < periods; i++) {
    amt = compute_interest(amt, period_rate);
  }
  return amt;
}

int main() {
  double starting = 100.0;
  for (int months = 1; months <= 24; months++) {
    double ending = compound_interest(starting, 0.075, 12, months);
    cout << "$" << starting << " becomes " << ending << " after "
        << months << " months at an APR of " << 0.75 << "%" << endl;
  }
}
