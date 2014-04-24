// passbyvalue.cpp
#include <iostream>
using namespace std;

void doubleIt(int x) {
  x = x * 2;
  cout << "&x = " << &x << " :: x = " << x << endl;
}

int main() {

  int x = 5;
  cout << "&x = " << &x << " :: x = " << x << endl;
  doubleIt(x);
  cout << "&x = " << &x << " :: x = " << x << endl; 

  return 0;
}
