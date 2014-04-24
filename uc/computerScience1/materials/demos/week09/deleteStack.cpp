// Example 11 deleteStack.cpp
#include <iostream>
using namespace std;

int main() {

  int x = 42;
  int* y = &x;

  // y is a pointer, but to something on the stack.
  // delete will not work
  delete y;

  return 0;
}
