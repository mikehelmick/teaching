// Example 15 - expand.cpp
#include <iostream>
#include <cstdlib>
using namespace std;


int* expand(int* orig, int &size, int &capacity) {
  if (size == capacity) {
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
  cout << "adding " << value << " to position " << size << endl;
  addTo[size++] = value;
  return addTo;
}

int main() {

  int size = 0;
  int capacity = 1;
  int* arr = new int[capacity];

  for (int i = 0; i < 40; i++) {
    arr = add(i, arr, size, capacity);
  }

  cout << "done: final size: " << size << " and capacity: " << capacity << endl;
  // final cleanup
  delete[] arr;
  arr = NULL;
}
