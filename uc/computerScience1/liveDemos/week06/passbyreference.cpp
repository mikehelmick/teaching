#include <iostream>
using namespace std;

void doubleIt(int &y) {
  y = y * 2;
  cout << "&y = " << &y << " :: y = " << y << endl;
}

int main() {
  int x = 5;
  cout << "&x = " << &x << " :: x = " << x << endl;
  doubleIt(x);
  cout << "&x = " << &x << " :: x = " << x << endl;
}
