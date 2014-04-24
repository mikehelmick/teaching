// Example 14 - reverse.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int* reverse(int arr[], int size) { 
  // Create a dynamic array
  int* reversed = new int[size];

  int* head = reversed;
  int* tail = &arr[size - 1];

  for (int i = 0; i < size; i++) {
    *head = *tail;
    head++;
    tail--;
  }
  return reversed;
}

int main() {
  const int size = 10;
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }

  int* reversed = reverse(arr, size);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " -- " << reversed[i] << endl;
  }

  // Must delete reversed
  delete[] reversed;
}

