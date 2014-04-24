// Example 02 - week09/ints.cpp

#include <iostream>
using namespace std;

int main() {
  int x = 42;

  cout << "x = " << x
     << " &x = " << &x << endl;

  int* y = &x;
  cout << "y = " << y
     << " &y = " << &y << endl;
  cout << " *y = " << *y << endl;



}
