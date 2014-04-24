/*
 * Recursive implementaiton of fib sqeuence.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long fib(unsigned long long num) {
  if (num == 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  }

  return fib(num - 1) + fib(num - 2);
}

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    cout << "I need a number!" << endl;
    return 1;
  }

  unsigned long long number = atoi(argv[1]);
  cout << "Computing fib(" << number << ")" << endl;
  for (unsigned long long i = 0; i <= number; i++) {
    cout << "fib(" << i << ") = " << fib(i) << endl;
  }
}
