#include <iostream>
using namespace std;

int main() {
  int size = 10;
  int myArray[size];

  for (int i = 0; i < size; i++) {
    myArray[i] = 100 * (i + 1);
  }

  for (int i = 0; i < size; i++) {
    cout << "value at myArray[" << i << "] = " << myArray[i] << endl;
  }

  // Addresses
  cout << "&myArray = " << &myArray << endl;

  for (int i = 0; i < size; i++) {
    cout << "&myArray[i] = " << &myArray[i] << endl;
  }

  return 0;
}
