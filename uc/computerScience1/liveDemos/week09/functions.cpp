// Example 7 - functions.cpp
//
#include <iostream>
using namespace std;

void doubleIt(int* x) {
  // Code it either way.
  // *x *= 2;
  *x = *x * 2;
}

int main() {
  int x = 42;
  int* y = &x;

  cout << "y = " << y << " and *y = " << *y << endl;
  doubleIt(y);
  cout << "y = " << y << " and *y = " << *y << endl;
  cout << "x = " << x << " and &x = " << &x << endl;
}
