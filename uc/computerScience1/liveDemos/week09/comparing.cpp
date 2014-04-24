// comparing.cpp
#include <iostream>
using namespace std;

int main() {
  int x = 42;
  int y = 50;
  int* ptr1 = &x;
  int* ptr2 = &x;
  int* ptr3 = &y;

  if (ptr1 == ptr2) {
    cout << "ptr1 == ptr2" << endl;
    cout << ptr1 << " == " << ptr2 << endl;
  }

  if (ptr1 != ptr3) {
    cout << "ptr1 != ptr3" << endl;
    cout << ptr1 << " != " << ptr3 << endl;
  }
}
