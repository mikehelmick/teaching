#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int SIZE = 10;

void randArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    a[i] = rand() % 100;
  }
}

void copyArray(int s[], int t[], int size) {
  for (int i = 0; i < size; i++) {
    t[i] = s[i];
  }
}

void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << setw(3) << a[i];
  }
  cout << endl;
}

void bubbleSort(int arr[], int size) {
  cout << "BUBBLE SORT" << endl;
  bool sorted = false;
  int upTo = size - 1;
  while (!sorted) {
    printArray(arr, size);
    sorted = true; // Assume we will sort it this time!
    for (int i = 0; i < upTo; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = false;
      }
    }
    // can eliminate 1 element from consideration
    upTo--;
  }
  printArray(arr, size);
  cout << "DONE WITH BUBBLE SORT" << endl;
}

void selectionSort(int arr[], int size) {
  cout << "SELECTION SORT" << endl;
  for (int i = 0; i < size - 1; i++) {
    int point = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[i]) {
        point = j;
      }
    }
    if (point != i) {
      int temp = arr[i];
      arr[i] = arr[point];
      arr[point] = temp;
    }
    printArray(arr, size);
  }

  printArray(arr, size);
  cout << "DONE WITH SELECTION SORT" << endl;
}

int main() {
  int source[SIZE];
  randArray(source, SIZE);

  int arr[SIZE];
  copyArray(source, arr, SIZE);

  bubbleSort(arr, SIZE);

  copyArray(source, arr, SIZE);
  selectionSort(arr, SIZE);

  return 0;
}
