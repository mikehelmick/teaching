#include <iostream>
using namespace std;

int main() {
  int x = 40;
  int y = 60;
  int z;
  cout << "x: " << x << " y: " << y << " z: " << z << endl;

  cout << "Enter new values for x, y, and z:" << endl;
  cin >> x >> y >> z;

  int a = x % z;
  int b = y % z;
  int c = a + b;
  cout << "a: " << a << " b: " << b << " c: " << c << endl;
  return 0;
}