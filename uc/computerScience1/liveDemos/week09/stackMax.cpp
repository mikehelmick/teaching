/**
 * A program to intentionally run out of stack space w/ rescursive calls
 */

#include <iostream>
#include <cstdlib>
using namespace std;

void infinite(long num) {
  cout << num << endl;
  return infinite(num + 1);
}

int main() {
  infinite(1);
  return 0;
}
