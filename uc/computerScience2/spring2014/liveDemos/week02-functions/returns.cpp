#include <iostream>
using namespace std;

void someFunction(int a, int b, int c) {
  cout << (a+b+c) << endl;
}

void anotherFunction() {
  int a = 6;
  int b = 7;
  int c = 8;
  int d = 9;
}

int multiply(int a, int b) {
  a * b;
}

int main() {
  anotherFunction();
  int c = multiply(2, 4);
  cout << "2*4 = " << c << endl;

  return 0;
}

