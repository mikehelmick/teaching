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

int main() {
  int values[10] = {2, 4, 7, 8, 10, 12, 14, 16, 18, 20};

  for (int searchFor = 0; searchFor <= 21; searchFor++) {
    cout << "Location of " << setw(2) << searchFor << " is " 
        << setw(3) << linearSearch(values, 10, searchFor) << endl;
  }

}
