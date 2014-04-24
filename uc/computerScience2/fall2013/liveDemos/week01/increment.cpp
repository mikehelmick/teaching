#include <iostream>

using namespace std;

int main() {
  int x = 6;

  int a = 5 + x++;

  /**
  int tmp = 5 + x;
  int a = tmp;
  x = x + 1;
  */

  /**
  x = x + 1;
  int b = 5 + x;
  */
  int b = 5 + ++x;

  cout << "a = " << a << " b = " << b << endl;
}
