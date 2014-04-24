#include <iostream>
using namespace std;

int main() {

  short x = 32760;

  for (int i = 0; i < 20; i++) {
    x++;
    cout << x << endl;
  }

  cout << "-------" << endl;
  for (int i = 0; i < 20; i++) {
    x--;
    cout << x << endl;
  }


  short y = 32769;
  cout << "y is " << y << endl;
}
