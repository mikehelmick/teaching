#include <iostream>
using namespace std;

int main() {
  cout << "Enter array size: ";

  int size;
  cin >> size;

  int myArray[size];
  for (int i = 0; i < size; i++) {
    myArray[i] = i;
    cout << myArray[i] << " ";
  }
  cout << endl;
}

