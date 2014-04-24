#include <iostream>
using namespace std;

void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void doubleElements(int a[], int size) {
  for (int i = 0; i < size; i++) {
    a[i] *= 2;
  }
}

void asConst(const int a[], int size) {
  int x = (int) a;
  int* y = (int*) x;

  for (int i = 0; i < size; i++) {
    y[i] *= 3;
  }
}

int main() {
  int size = 10;

  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = i * 3;
  }

  printArray(arr, size);
  doubleElements(arr, size);
  printArray(arr, size);

  asConst(arr, size);
  printArray(arr, size);

  return 0;
}
