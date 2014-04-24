// shared.cpp
#include <iostream>
using namespace std;

int main() {
  int x = 42;
  int* ptr1 = &x;
  int* ptr2 = ptr1;

  cout << " ptr1: " << ptr1 << " - ptr2: " << ptr2 << endl;
  cout << "*ptr1: " << *ptr1 << " - *ptr2: " << *ptr2 << endl;
}
