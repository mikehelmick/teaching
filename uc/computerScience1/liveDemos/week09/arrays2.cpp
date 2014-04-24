// arrays2.cpp
#include <iostream>
using namespace std;

void printArrayWithPointers(int a[], int size) {
  int* ptr = a;

  for (int counter = 0; counter < size; counter++) {
    cout << *ptr << " ";
    ptr++;
  }
  cout << endl;
}

int main() {
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = (i + 1) * 2;
  }
  printArrayWithPointers(arr, 10);
}
