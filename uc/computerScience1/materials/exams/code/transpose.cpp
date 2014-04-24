#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 5;

void print(int arr[SIZE][SIZE]) {
  for (int r = 0; r < SIZE; r++) {
    for (int c = 0; c < SIZE; c++) {
      cout << setw(3) << arr[r][c];
    }
    cout << endl;
  }
}

int main() {
  int arr[SIZE][SIZE];
  int counter = 0;
  for (int r = 0; r < SIZE; r++) {
    for (int c = 0; c < SIZE; c++) {
      arr[r][c] = counter++;
    }
  }
  print(arr);
  cout << "----------" << endl;

  /*
  for (int r = 0; r < SIZE; r++) {
    for (int c = r + 1; c < SIZE; c++) {
      int tmp = arr[r][c];
      arr[r][c] = arr[c][r];
      arr[c][r] = tmp;
    }
  }
  */
  
  {
    int temp = 0;
    for (int r = 0; r < SIZE; r++) {
      for (int c = 0; c < SIZE; c++) {
        temp = arr[r][c];
        arr[r][c] = arr[c][r];
        arr[c][r] = temp;
      }
    }
  }
  
  print(arr);
  
  return 0;
}