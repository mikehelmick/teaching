#include <iostream>
using namespace std;

int main() {
  int x = 5;
  int y = 10;
  int z = 15;

  int a = ++x + x++ + --y + y-- + z++ + --z;

  cout << x << endl;
  cout << y << endl;
  cout << z << endl;
  cout << a << endl;
}
