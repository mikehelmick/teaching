#include <iostream>
using namespace std;

int main() {

  int myArray[10];

  for (int i = 0; i < 10; i++) {
    myArray[i] = 100 * (i + 1);
  }

  for (int i = 0; i < 10; i++) {
    cout << "value at myArray[" << i << "] = " << myArray[i] << endl;
  }

  // Addresses
  cout << "&myArray = " << &myArray << endl;

  for (int i = 0; i < 10; i++) {
    cout << "&myArray[i] = " << &myArray[i] << endl;
  }

  return 0;
}
