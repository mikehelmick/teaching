#include <iostream>
using namespace std;

int main() {
  int* a = new int;
  *a = 45;
  int* b = a;
  cout << "a=" << *a << " b=" << *b << endl;
  *b = 55;
  cout << "a=" << *a << " b=" << *b << endl;
  b = new int;
  *b = 65;
  cout << "a=" << *a << " b=" << *b << endl;
  *a = 75;
  cout << "a=" << *a << " b=" << *b << endl;
  delete a;
  a = NULL;
  b = NULL;
}