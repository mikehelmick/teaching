#include <iostream>
using namespace std;

#include <Fraction.h>

int main() {
  Fraction a(4, 6);
  Fraction b(8, 12);

  cout << "a: " << a.toString() << endl;
  cout << "b: " << b.toString() << endl;

  a.divide(b);
  cout << "a: " << a.toString() << endl;

}