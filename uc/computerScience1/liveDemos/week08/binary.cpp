#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int NOT_FOUND = -1;

int binarySearch(int arr[], int size, int target) {
  int min = 0;
  int max = size - 1;
  int mid = 0;

  while (min <= max) {
    int mid = (max - min) / 2 + min;
    if (arr[mid] == target) {
      return mid;
    }

    if (target < arr[mid]) {
      // adjust max to be < mid
      max = mid - 1;
    } else {
      // adjust min to be > mid
      min = mid + 1;
    }
  }

  // Must not have found the value
  return NOT_FOUND;
}

int main() {
  int values[10] = {2, 4, 7, 8, 10, 12, 14, 16, 18, 20};

  for (int searchFor = 0; searchFor <= 21; searchFor++) {
    cout << "Location of " << setw(2) << searchFor << " is " 
        << setw(3) << binarySearch(values, 10, searchFor) << endl;
  }
}
