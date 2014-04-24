#include <iostream>

#include <Fraction.h>

int main(int argc, char* argv[]) {
  
  Fraction f1(1, 2);
  Fraction f2(1, 3);

  Fraction res = f1 + f2;
  cout << f1.toString() << " + " << f2.toString()
      << " = " << res.toString() << endl;
  
  res = f1 - f2;
  cout << f1.toString() << " - " << f2.toString()
      << " = " << res.toString() << endl;
  

  res = f1 * f2;
  cout << f1.toString() << " * " << f2.toString()
      << " = " << res.toString() << endl;

  res = f1 / f2;
  cout << f1.toString() << " * " << f2.toString()
      << " = " << res.toString() << endl;

  bool cmp = f1 > f2;
  cout << f1.toString() << " > " << f2.toString()
      << " = " << cmp << endl;

  cmp = f1 < f2;
  cout << f1.toString() << " < " << f2.toString()
      << " = " << cmp << endl;

  cmp = f1 == f2;
  cout << f1.toString() << " == " << f2.toString()
      << " = " << cmp << endl;

  Fraction f3(f1);
  cmp = f1 == f3;
  cout << f1.toString() << " == " << f2.toString()
      << " = " << cmp << endl;

  return 0;
}