#include <iostream>
using namespace std;

int main() {
  int x = 42;
  int* y = &x;

  // y is a pointer, but it points to something on the stack
  // (i.e. a local variable)
  delete y;

  return 0;
}
