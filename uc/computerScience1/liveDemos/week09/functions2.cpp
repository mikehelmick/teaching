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

  cout << "x = " << x << " and &x = " << &x << endl;
  doubleIt(&x);
  cout << "x = " << x << " and &x = " << &x << endl;
}
