/*
 * gcd.cpp
 * Calculate the greatest common divisor, recursively
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(int argc, char* argv[]) {
  if (argc <= 2) {
    cout << "Enter 2 numbers." << endl;
    return 0;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
  return 0;
}

