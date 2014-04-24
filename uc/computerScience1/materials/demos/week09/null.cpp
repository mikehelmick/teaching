// Example 03 - week09/null.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int* x = NULL;

  // Attempt to use x
  *x = 15;

  cout << *x << endl;
}
