#include <iostream>
using namespace std;

int doubleIt(int x) {
  cout << "d &x = " << &x << " :: x = " << x << endl;
  x = x * 2;
  cout << "d &x = " << &x << " :: x = " << x << endl;
}

int main() {

  int x = 5;
  cout << "m &x = " << &x << " :: x = " << x << endl;
  doubleIt(x);
  cout << "m &x = " << &x << " :: x = " << x << endl;

  return 0;
}
