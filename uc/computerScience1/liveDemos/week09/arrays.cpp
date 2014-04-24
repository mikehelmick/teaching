// arrays.cpp
#include <iostream>
using namespace std;

void printArray(int* arr, int size) {
  cout << "arr=" << arr << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i]
       << " vs "
       << *(arr + i)
       << endl;
    cout << &arr[i]
       << " vs "
       << (arr + i)
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
