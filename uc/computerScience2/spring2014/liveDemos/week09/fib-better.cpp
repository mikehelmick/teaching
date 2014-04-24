/*
 * A better recursive implementaiton of fib sqeuence.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long fibBack(int dest, int location, unsigned long long n2, unsigned long long n1) {
  if (dest <= location) {
    return n1 + n2;
  }
  return fibBack(dest, location + 1, n1, n1 + n2);
}


unsigned long long fib(int num) {
  if (num == 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  }
  // Since I need to pass more info, I will put the defaults in for the caller.
  return fibBack(num, 2, 0, 1); // bottom, correct starting sequence
}

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    cout << "I need a number!" << endl;
    return 1;
  }

  int number = atoi(argv[1]);
  cout << "Computing fib(" << number << ")" << endl;
  for (int i = 0; i <= number; i++) {
    cout << "fib(" << i << ") = " << fib(i) << endl;
  }
}
