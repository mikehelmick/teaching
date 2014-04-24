#include <iostream>
using namespace std;

int main() {

  int* x = new int;
  *x = 42;

  delete x;
  // Good practice, set pointer to NULL after delete
  x = NULL;

  // Double delete - we already deleted x.
  delete x;

  return 0;
}
