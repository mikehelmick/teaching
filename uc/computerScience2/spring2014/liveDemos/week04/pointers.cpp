#include <iostream>
using namespace std;

int main() {
  int a = 5;
  int* b;
  b = &a;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "*b: " << *b << endl;

  b += 3000;
  cout << "b: " << b << endl;
  cout << "*b: " << *b << endl;
}