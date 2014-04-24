#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  int a[4][5];

  // Part 1
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 5; c++) {
      cout << &a[r][c] << "  ";
    }
    cout << endl;
  }

  // Part 2
  // calculate offsets
  int prev = (int) &a;
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 5; c++) {
      int cur = (int) &a[r][c];
      int difference = cur - prev;
      cout << setw(4) << difference;
      prev = cur;
    }
    cout << endl;
  }

  return 0;
}
