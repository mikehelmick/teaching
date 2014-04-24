#include <iostream>
#include <iomanip>
using namespace std;

void printArray(int* arr, int rS, int cS) {
  for (int r = 0; r < rS; r++) {
    for (int c = 0; c < cS; c++) {
      cout << setw(3) << arr[r*rS + c];
    }
    cout << endl;
  }
}

int main() {
  int* arr = new int[5*5];
  for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 5; c++) {
      arr[r*5 + c] = r * c;
    }
  } 
  printArray(arr, 5, 5);
}
