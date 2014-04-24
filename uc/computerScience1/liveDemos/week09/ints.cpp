// ints.cpp
#include <iostream>
using namespace std;

int main() {
  int x = 42;

  cout << "x = " << x
     << " &x = " << &x
     << endl;

  int* y = &x;
  cout << "y = " << y
     << " &y = " << &y
     << " *y = " << *y
     << endl;

  *y = 54;
  cout << "x = " << x
     << " &x = " << &x
     << endl;

}
