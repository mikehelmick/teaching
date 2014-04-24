#include <iostream>
#include <climits>
using namespace std;

int main() {

  int a = INT_MAX;
  long long x = LLONG_MAX - 5;

  cout << "a=" << a << " x=" << x << endl;
  cout << "sizeof(a) = " << sizeof(a) << endl;
  cout << "sizeof(x) = " << sizeof(x) << endl << endl;

  int b = x;
  long long y = a;
  cout << "b=" << b << " expected=" << x << endl;
  cout << "y=" << y << " expected=" << a << endl;

  return 0;
}
