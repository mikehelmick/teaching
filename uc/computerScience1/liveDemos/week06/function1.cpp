#include <iostream>
using namespace std;

int square(int val) {
  return val * val;
}

int main() {
  int x = 6;
  int x2 = square(x);

  cout << "x = " << x << endl;
  cout << "x^2 = " << x2 << endl;
}
