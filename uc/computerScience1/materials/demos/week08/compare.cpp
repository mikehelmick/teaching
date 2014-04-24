#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int NOT_FOUND = -1;

int linearSearch(int arr[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return NOT_FOUND;
}

int binarySearch(int arr[], int size, int target) {
  int min = 0;
  int max = size - 1;
  int mid = 0;

  while (min <= max) {
    mid = (max - min) / 2 + min;
    if (arr[mid] == target) {
      return mid;
    } else if (target > arr[mid]) {
      min = mid + 1;
    } else {
      max = mid - 1; 
    }
  }
  // Must not have found the value
  return NOT_FOUND;
}

int main() {
  int size = 100000;
  int searchMax = size * 2 + 2;
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = i * 2;
  }

  int linearFound = 0;
  int binaryFound = 0;
 
  long long start = time(NULL);
  cout << "Linear search: " << start << " ... ";
  for (int searchFor = -1; searchFor <= searchMax; searchFor++) {
    if (linearSearch(arr, size, searchFor) != NOT_FOUND) {
      linearFound++; 
    }
  }
  long long end = time(NULL);
  cout << end << "   found: " << linearFound << endl;
  cout << "  time: " << (end - start) << endl;

  start = time(NULL);
  cout << "Binary search: " << start << " ... ";
  for (int searchFor = -1; searchFor <= searchMax; searchFor++) {
    if (binarySearch(arr, size, searchFor) != NOT_FOUND) {
      binaryFound++; 
    }       
  }
  end = time(NULL);
  cout << end << "   found: " << binaryFound << endl;
  cout << "  time: " << (end - start) << endl;
}
