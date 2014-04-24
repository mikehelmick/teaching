// Example 01 - week09/arrays.cpp

#include <iostream>
using namespace std;

void printArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i]
       << " vs "
       << *(arr + i)
       << endl;
  }
}

int main() {
  int x[10];
  for (int i = 0; i < 10; i++) {
    x[i] = i;
  }

  printArray(x, 10);
}
