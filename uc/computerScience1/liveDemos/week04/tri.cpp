#include <iostream>
using namespace std;

int main() {
  cout << "What is y? ";
  int y = 0;
  cin >> y;
  
  int x = 0;
  if (y > 23) {
    x = y * 2;
  } else {
    x = y + 2;
  }

  int z = y > 23 ? y * 2 : y + 2;
  
  cout << "x is " << x << endl;
  cout << "z is " << z << endl;
}