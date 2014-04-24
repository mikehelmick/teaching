#include <iostream>
using namespace std;

void double_entries(int arr[], int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    arr[i] = arr[i] * 2;
  }
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "arr[" << i << "]=" << arr[i] << endl;
  }
}

void add_entry(int arr[], int& size, const int capacity) {
  if (size >= capacity) {
    cerr << "ERROR - array at capacity" << endl;
    return;
  }
  
  if (size == 0) {
    arr[0] = 1;
    size++;
    return;
  }

  arr[size] = arr[size-1] + 2;
  size++;
}

int main() {
  int size = 5;
  const int capacity = 10;
  int my_array[capacity] = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0};

  print_array(my_array, size);
  double_entries(my_array, size);
  print_array(my_array, size);

  cout << "--" << endl;
  add_entry(my_array, size, capacity);
  print_array(my_array, size);
}
