#include <iostream>
using namespace std;

// This is global.
int x = 7;

int coolFun(int z) {
  cout << " x is " << x << " and z is " << z << endl;

  {
    float x = 574.9;
    cout << " x is " << x << endl;
  }

  cout << " x is " << x << " and z is " << z << endl; 
  return 0;
}

int myFun(int x) {
  cout << " x is " << x << endl;
  coolFun(x);
  return x * 2;
}

int main() {
  int y = 4;
  myFun(y);
}
