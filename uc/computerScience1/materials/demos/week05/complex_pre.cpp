// week05/complex_pre.cpp

#include <iostream>
using namespace std;

int main() {
  
  int x = 5;
  int y = 10;
  int z = 15;

  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
  cout << "calculate a" << endl;

  int a = ++x + x++ + --y + y-- + z++ + --z;
  
  cout << "a = " << a << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
  
}