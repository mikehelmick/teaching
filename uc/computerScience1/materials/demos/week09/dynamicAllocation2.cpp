// Example 10 dynamicAllocation.cpp
#include <iostream>
using namespace std;

int main() {

  // Allocate 1000 integer pointers
  for (int i = 0; i < 1000000; i++) {
    int* x = new int;
    // x is a pointer, we must dereference it to use it
    *x = i;
    delete x;
  }

  return 0;
}
