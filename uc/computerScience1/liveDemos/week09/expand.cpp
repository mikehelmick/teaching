// Expand.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

int* expand(int* orig, int &size, int &capacity) {
  if (size == capacity) {
    // resize the array
    cout << "array full! Resizing from " << capacity << " to " << capacity * 2 << endl;
    capacity *= 2;
    int* newArr = new int[capacity];  
    for (int i = 0; i < size; i++) {
      newArr[i] = orig[i];
    }
    delete[] orig;
    orig = NULL;
    return newArr;
  }
  return orig;
}

int* add(int value, int* arr, int &size, int &capacity) {
  int* addTo = expand(arr, size, capacity);
  // I know that addTo is big enough
  cout << "adding " << value << " to position " << size << endl;
  addTo[size++] = value;
  return addTo;  
}

int main() {
  int size = 0;
  int capacity = 1;
  int* arr = new int[capacity];

  for (int i = 0; i < 10000000; i++) {
    arr = add(i, arr, size, capacity);
  }

  cout << "done: final size: " << size << " final capacity: " << capacity << endl;
  delete[] arr;
  arr = NULL;
}
