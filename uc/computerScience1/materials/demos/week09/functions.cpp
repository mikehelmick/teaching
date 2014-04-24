// Example 07 - functions.cpp

#include <iostream>
using namespace std;

void doubleIt(int* x) {
  *x = *x * 2;
}

int main() {

  int x = 42;
  int* y = &x;
  cout << "y is " << y << " *y = " << *y << endl;
  doubleIt(y);
  cout << "y is " << y << " *y = " << *y << endl;
}
