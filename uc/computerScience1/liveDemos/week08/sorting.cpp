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
  printArray(arr, size);
  bool sorted = false;
  int maxIdx = size - 1;
  while (!sorted) {
    sorted = true;
 
    for (int i = 0; i < size; i++) {
      if (arr[i] > arr[i + 1]) {
        sorted = false;

        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
    }
    printArray(arr, size);
    maxIdx--;
  }

  printArray(arr, size);
  cout << "DONE WITH BUBBLE SORT" << endl;
}

void selectionSort(int arr[], int size) {
  cout << "SELECTION SORT" << endl;
  printArray(arr, size);
  for (int fill = 0; fill < size - 1; fill++) {
    int posMin = fill;
    for (int next = fill + 1; next < size; next++) {
      if (arr[next] < arr[posMin]) {
        posMin = next;
      }
    }
    if (posMin != fill) {
      int tmp = arr[fill];
      arr[fill] = arr[posMin];
      arr[posMin] = tmp;
    }
    printArray(arr, size);
  }

  printArray(arr, size);
  cout << "DONE WITH SELECTION SORT" << endl;
}

int main() {
  srand(time(NULL));
  int source[SIZE];
  randArray(source, SIZE);

  int arr[SIZE];
  copyArray(source, arr, SIZE);

  //bubbleSort(arr, SIZE);

  //copyArray(source, arr, SIZE);
  selectionSort(arr, SIZE);

  return 0;
}
