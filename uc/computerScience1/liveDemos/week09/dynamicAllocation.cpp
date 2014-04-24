#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 1000000; i++) {
      int* x = new int;
      *x = i;
    }

  return 0;
}
