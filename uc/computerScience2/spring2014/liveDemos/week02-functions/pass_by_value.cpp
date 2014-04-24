#include <iostream>
using namespace std;

int square(int input) {
  cout << "input=" << input << " addressOfInput=" << &input << endl;
  input = input * input;
  return input;
}

int main() {
  int x = 42;
  cout << "x = " << x << " addressOfX=" << (&x) << endl;
  int y = square(x);
  cout << "function called" << endl;
  cout << "addressOfY=" << &y << endl;
  cout << "x = " << x << " y = " << y << endl;

  return 0;
}
