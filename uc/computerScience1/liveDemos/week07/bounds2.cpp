#include <iostream>
using namespace std;

int main() {
  

  int myArray[100];
  int a = 50;
  int b = 50;
  int c = 50;
  int d = 50;
  int e = 50;

/*cout << &myArray[99] << endl;
  cout << &a << endl;
  cout << &b << endl;
  cout << &c << endl;
  cout << &d << endl;
  cout << &e << endl;
  */

  cout << a << " " << b << " " << c << " " << d << " " << e << endl;

  for (int i = 0; i < 105; i++) {
    myArray[i] = i;
  }

  cout << a << " " << b << " " << c << " " << d << " " << e << endl;

  return 0;
}

