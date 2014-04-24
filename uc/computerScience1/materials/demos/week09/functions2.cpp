// Example 07 - functions.cpp

#include <iostream>
using namespace std;

void doubleIt(int* x) {
  *x = *x * 2;
}

int main() {

  int x = 42;
  cout << "x is " << x << " &x = " << &x << endl;
  doubleIt(&x);
  cout << "x is " << x << " &x = " << &x << endl;
}
