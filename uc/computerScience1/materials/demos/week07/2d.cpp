#include <iostream>
#include <iomanip>
using namespace std;

const int DIM = 15;

int main() {

  int table[DIM][DIM];

  for (int row = 0; row < DIM; row++) {
    for (int col = 0; col < DIM; col++) {
      table[row][col] = row * col;
    }
  }

  // print out
  for (int row = 0; row < DIM; row++) {
    for (int col = 0; col < DIM; col++) {
      cout << setw(5) << table[row][col];
    }
    cout << endl;
  }

  return 0;
}
