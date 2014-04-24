/*
 * Recursive implementaiton of factorial
 */

#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long fact(unsigned long long number) {
  // BASE CASE - factorial of 0 is 1, by definition
  if (number == 0) {
    return 1;
  }
  return number * fact(number - 1);
}


int main(int argc, char* argv[]) {
  if (argc <= 1) {
    cout << "I need a number!" << endl;
    return 1;
  }

  unsigned long long number = atoi(argv[1]);
  cout << "Computing fact(" << number << ")" << endl;
  for (unsigned long long i = 0; i <= number; i++) {
    cout << "fact(" << i << ") = " << fact(i) << endl;
  }
}
