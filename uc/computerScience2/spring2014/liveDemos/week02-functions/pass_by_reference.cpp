#include <iostream>
using namespace std;

void square(int &input) {
  cout << "input = " << input << " @ " << &input << endl;
  input = input * input;
  cout << "input = " << input << " @ " << &input << endl;
}

int main() {
  int x = 42;
  cout << "x = " << x << " @ " << &x << endl;
  square(x);
  cout << "function called" << endl;
  cout << "x = " << x << " @ " << &x << endl;

  return 0;
}
