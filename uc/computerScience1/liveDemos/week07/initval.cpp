#include <iostream>
using namespace std;

int main() {

  int powers[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

  int cPowers[10];
  cPowers[0] = 1;
  for (int i = 1; i < 10; i++) {
    cPowers[i] = 2 * cPowers[i - 1];
  }

  for (int i = 0; i < 10; i++) {
    cout << powers[i] << " " << cPowers[i] << endl;

  }
  cout << endl;
}
