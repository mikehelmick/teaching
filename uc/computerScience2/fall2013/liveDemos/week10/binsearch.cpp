#include <iostream>

using namespace std;

int binSearch(int target, int arr[], int min, int max) {
  if (min > max) {
    return -1;
  }
  
  int midPoint = (max - min) / 2 + min;
  if (arr[midPoint] == target) {
    return midPoint;
  }
  
  if (target > arr[midPoint]) {
    return binSearch(target, arr, midPoint + 1, max);
  } else {
    // I know it is less than midPoint
    return binSearch(target, arr, min, midPoint - 1);
  }
}

int binSearch(int target, int arr[], int size) {
  int min = 0;
  int max = size;
  return binSearch(target, arr, min, max);
}

int binSearch2(int target, int arr[], int size) {
  int min = 0;
  int max = size - 1;
  
  while (!(min > max)) {
    int midPoint = (max - min) / 2 + min;
    if (arr[midPoint] == target) {
      return midPoint;
    }
    
    if (target > arr[midPoint]) {
      min = midPoint + 1;
    } else {
      max = midPoint - 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int size = 10;
  
  for (int i = 1; i <= 20; i++) {
    int index = binSearch2(i,  arr, size);
    cout << "index of " << i << " is " << index << endl;
  }
}