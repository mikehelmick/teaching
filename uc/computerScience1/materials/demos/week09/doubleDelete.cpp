// Example 12 doubleDelete.cpp
#include <iostream>
using namespace std;

int main() {

  int* x = new int;
  *x = 42;

  delete x;

  // double delete
  // OK, if set to NULL first.
  // x = NULL;
  delete x;

  return 0;
}
