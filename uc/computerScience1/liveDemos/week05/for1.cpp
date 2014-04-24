#include <iostream>
using namespace std;

int main() {

  for (int i = 0; i < 10; i++) {
    cout << i << endl;
  }

  for (double i = 0; i < 10; i = i + 1.1) {
    cout << i << endl;
  }

  return 0;
}
