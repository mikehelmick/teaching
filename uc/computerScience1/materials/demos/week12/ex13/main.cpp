
#include <iostream>
using namespace std;

#include <Fraction.h>

int main() {

  Fraction a(2, 3);
  Fraction b(6, 11);

  cout << "a: " << a.toString() << endl;
  cout << "b: " << b.toString() << endl;

  a.add(b);

  cout << "a: " << a.toString() << endl;

  Fraction c(1, 2);
  Fraction d(3, 2);
  cout << "c: " << c.toString() << endl;
  cout << "d: " << d.toString() << endl;

  c.add(d);

  cout << "c: " << c.toString() << endl;
}