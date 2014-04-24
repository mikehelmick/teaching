#include <iostream>
#include <cstdlib>
using namespace std;

int sumOfDigits(int number) {
  if (number < 10) {
    return number;
  }
  return (number % 10) + sumOfDigits(number / 10);
}

bool isNiven(int number) {
  if (number < 1) {
    return false;
  }
  int digitSum = sumOfDigits(number);
  return number % digitSum == 0; 
}

int main() {
  for (int i = 0; i <= 50; i++) {
    cout << i << " " << isNiven(i) << endl;
  }
}