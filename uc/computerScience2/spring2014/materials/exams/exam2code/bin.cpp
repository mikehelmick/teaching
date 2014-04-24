#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int first, int last) {
  // BEGIN ANSWER
  if (first > last) {
    return -1;
  }
  int mid = (last - first) / 2 + first;
  if (arr[mid] == target) {
    return mid;
  } else if (target < arr[mid]) {
    return binarySearch(arr, target, first, last - 1);
  } else {
    return binarySearch(arr, target, mid + 1, last);
  }
  // END ANSWER
}

int binarySearch(int arr[], int size, int target) {
  return binarySearch(arr, target, 0, size - 1);
}

int main() {
  int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  
  for (int i = 0; i < 22; i++) {
    cout << i << ":" << binarySearch(arr, 10, i) << endl;
  }
}