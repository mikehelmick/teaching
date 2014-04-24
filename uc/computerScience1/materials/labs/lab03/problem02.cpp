#include <iostream>
using namespace std;

int minimum(int numA, int numB, int numC) {
  if (numA < numB && numA < numC) {
    return numA;
  } else if (numB < numA && numB < numC) {
    return numB;
  } else {
    return numC;
  }
}

int maximum(int numA, int numB, int numC) {
  if (numA > numB && numA > numC) {
    return numA;
  } else if (numB > numA && numB > numC) {
    return numB;
  }
  return numC;
}

int main() {
  cout << "Enter three numbers: ";
  int numA = 0;
  int numB = 0;
  int numC = 0;
  cin >> numA >> numB >> numC;
  int min = minimum(numA, numB, numC);
  int max = maximum(numA, numB, numC);
  cout << "Minimum of " << numA << ", " << numB << ", and " << numC << " is " << min << endl;
  cout << "Maximum of " << numA << ", " << numB << ", and " << numC << " is " << max << endl;
}
