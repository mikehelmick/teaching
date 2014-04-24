#include <iostream>
using namespace std;
 
void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
 
void modifyConstArray(const int a[], int size) {
  // Casualy interpret the address of the const array as an int
  int x = (int) a;
  // Re-interpret that int as a pointer
  int* y = (int*) x;
  // You can now easily change memory passed to you as const. Easy as pie.
  for (int i = 0; i < size; i++) {
    y[i] = -1;
  }
}
 
int main() {
  int size = 10;
 
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
 
  printArray(arr, size);
  modifyConstArray(arr, size);
  printArray(arr, size);
 
  return 0;
}
