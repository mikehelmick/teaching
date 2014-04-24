#include <iostream>
#include <cstdlib>

using namespace std;


void swap(int array[], int a, int b) {
  int tmp = array[a];
  array[a] = array[b];
  array[b] = tmp;
}

int pickPivotIndex(int array[], int start, int end) {
  int middle = (start + end)/2;
  if (array[start] < array[middle] 
      && array[middle] < array[end]) {
    return middle;
  } else if (array[middle] < array[start]
      && array[start] < array[end]) {
    return start;
  }
  return end;
}

// Returns the index of the pivot element, which
// we know is in the right spot now.
int partition(int array[], int start, int end) {
  int pivotIndex = pickPivotIndex(array, start, end);
  if (pivotIndex != start) {
    swap(array, start, pivotIndex);
  }
  int pivot = array[start];
  
  int up = start;
  int down = end;
  while (up < down) {
    while (up < end && pivot >= array[up]) {
      up++;
    }
    while (pivot < array[down]) {
      down--;
    }
    
    if (up < down) {
      swap(array, up, down);
    }
  }
  swap(array, start, down);
  return down;
}

void quicksort(int array[], int start, int end) {
  if (start < end) {
    int pivotIndex = partition(array, start, end);
    
    quicksort(array, start, pivotIndex - 1);
    quicksort(array, pivotIndex + 1, end);
  }
}

void quicksort(int array[], int size) {
  return quicksort(array, 0, size - 1);
}

int main() {
  srand(5);
  int size = 10;
  int* data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = rand() % 100;
  }
  
  quicksort(data, size);
  
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}



