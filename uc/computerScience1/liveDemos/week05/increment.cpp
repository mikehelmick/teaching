#include <iostream>
using namespace std;

int main() {

  {
    int x = 5;
    int y = 5 + ++x;
    cout << "x is " << x << " and y is " << y << endl;
  }

  {
    int x = 5;
    x = x + 1;
    int y = 5 + x;
    cout << "x is " << x << " and y is " << y << endl;
  }

}
