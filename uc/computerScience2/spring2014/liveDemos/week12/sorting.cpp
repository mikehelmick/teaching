#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int* genArray(int size) {
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
}

void printArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << setw(3) << arr[i];
  }
  cout << endl;
}

void swap(int* arr, int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void selectionSort(int* arr, int size) {
  for (int fill = 0; fill < size - 1; fill++) {
    int posMin = fill;
    for (int next = fill + 1; next < size; next++) {
      if (arr[next] < arr[posMin]) {
        posMin = next;
      }
    }
    // swap
    if (fill != posMin) {
      swap(arr, fill, posMin);
    }
    printArray(arr, size);
  }
}

void insertionSort(int* arr, int size) {
  for (int next = 1; next < size; next++) {
    int nextVal = arr[next];
    int nextPos = next;
    while (nextPos > 0 && arr[nextPos - 1] > nextVal) {
      arr[nextPos] = arr[nextPos - 1];
      nextPos--;
    }
    // nextPos is the right place for nextVal
    arr[nextPos] = nextVal;
    printArray(arr, size);
  }
}

void bubbleSort(int* arr, int size) {

  bool sorted = false;
  int maxElem = size - 1;
  while (!sorted) { 
    sorted = true; 
    for (int i = 0; i < maxElem; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr, i, i + 1);
        sorted = false;
        printArray(arr, size);
      }
    }
    maxElem--; 
    printArray(arr, size);
  }
}

void mergeSort(int* arr, int size) {
  if (size  <= 1) {
    return;
  }

  int halfSize = size / 2;
  int* leftTable = new int[halfSize];
  int* rightTable = new int[size - halfSize];
  for (int i = 0; i < halfSize; i++) {
    leftTable[i] = arr[i];
  }
  for (int i = 0; i < size - halfSize; i++) {
    rightTable[i] = arr[i + halfSize];
  }

  mergeSort(leftTable, halfSize);
  mergeSort(rightTable, size - halfSize);

  // Merge left table and right table together;
  int leftIdx = 0;
  int rightIdx = 0;
  int index = 0;

  while (leftIdx < halfSize && rightIdx < size - halfSize) {
    if (leftTable[leftIdx] < rightTable[rightIdx]) {
      arr[index] = leftTable[leftIdx];
      leftIdx++;
    } else {
      arr[index] = rightTable[rightIdx];
      rightIdx++;
    }
    index++;
  }
  while (leftIdx < halfSize) {
    arr[index++] = leftTable[leftIdx++]; 
  }
  while (rightIdx < size - halfSize) {
    arr[index++] = rightTable[rightIdx++];
  }

  printArray(arr, size);
  delete[] leftTable;
  delete[] rightTable;
}

int main() {
  srand(10);

  int size = 10;
  int* arr = genArray(size);
  printArray(arr, size);

  //selectionSort(arr, size);
  //insertionSort(arr, size);
  //bubbleSort(arr, size);
  mergeSort(arr, size);

  delete arr;
}
