#include <iostream>
using namespace std;

// todo(helmick): Document this function!
int magicTime(int a, int &b, const int &c) {
  a = c;
  b = 20;
}

int main() {
  int a = 10;
  int b = 30;
  int c;
  cout << "a: " << a << " b: " << b << " c: " << c << endl;
  c = b;
  magicTime(c, b, a);
  cout << "a: " << a << " b: " << b << " c: " << c << endl;
  return 0;
}