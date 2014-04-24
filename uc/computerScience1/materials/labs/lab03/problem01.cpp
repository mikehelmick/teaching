#include <iostream>
using namespace std;

int minimum(int numA, int numB) {
  if (numA < numB) {
    return numA;
  } else {
    return numB;
  }
}

int maximum(int numA, int numB) {
  if (numA > numB) {
    return numA;
  }
  return numB;
}

int main() {
  cout << "Enter two numbers: ";
  int numA = 0;
  int numB = 0;
  cin >> numA >> numB;
  int min = minimum(numA, numB);
  int max = maximum(numA, numB);
  cout << "Minimum of " << numA << " and " << numB << " is " << min << endl;
  cout << "Maximum of " << numA << " and " << numB << " is " << max << endl;
}
