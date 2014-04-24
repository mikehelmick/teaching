#include <iostream>
using namespace std;

int main() {

  double x = 1.333333333;
  double y = 1 + 1/3.0;

  cout << "sizeof x is " << sizeof(x) << endl;
  cout << "sizeof y is " << sizeof(y) << endl;

  if (x == y) {
    cout << " They are equal. " << endl;
  } 

  if (x > (y-0.0001) && x < (y + 0.0001)) {
    cout << "They are close enough" << endl;
  }

  return 0;
}
