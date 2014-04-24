#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10;

void print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << setw(3) << arr[i];
  }
  cout << endl;
}

void swap(int arr[], int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void someKindOfSort(int arr[], int size) {
  int rounds = size / 2 + 1;
  for (int it = 0; it < rounds; it++) {
	  cout << "it: " << it << " :: ";
    int pMi = it;
    int upperId = size - it - 1;
    int pMa = upperId;
    if (it >= upperId) {
      continue;
    }
    for(int idx = it; idx < size - it; idx++) {
      if (arr[idx] < arr[pMi]) {
        pMi = idx;
      }
      if (arr[idx] > arr[pMa]) {
        pMa = idx;
      }
    }
    if (pMi != it) {
      swap(arr, it, pMi);
      if (pMa == it) {
        pMa = pMi;
      }
    }
    if (pMa != upperId) {
      swap(arr, upperId, pMa);
    }
    print(arr, size);
  }
}

int main() {
  int arr[SIZE] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
  
  print(arr, SIZE);
  cout << "--sort--" << endl;
  someKindOfSort(arr, SIZE);
  cout << "--final--" << endl;
  print(arr, SIZE);

  return 0;
}
