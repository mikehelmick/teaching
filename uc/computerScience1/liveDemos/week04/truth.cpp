#include <iostream>
using namespace std;

int main() {
  
  int x = 0;
  int y = 2;
  int z = 4;

  if (x + y) {
    cout << x << "+" << y << " is true" << endl;
  }

  if (z - y) {
    cout << z << "-" << y << " is true" << endl;;
  }
  
  if (!(z - 2 * y)) {
    cout << z << "- 2*" << y << " is FALSE" << endl;
  }
}
