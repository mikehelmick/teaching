#include <iostream>
using namespace std;

int doubleIt(int i) {
  return i * 2;
}

int main() {
  int x = 42;
  cout << "x is " << x << endl;
  // LOGIC ERROR - ignoring the return value from doubleIt
  doubleIt(x);
  cout << "2 * x is " << x << endl;
}
