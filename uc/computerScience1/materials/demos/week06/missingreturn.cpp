// missingreturn.cpp
#include <iostream>
using namespace std;

int doubleIt(int x) {
  // remember - pass-by-value, x isn't going to change
  x = x * 2;
  // should have a return here
  double var = x * x * x * x * x * x;  
}

void disp(int x) {
  cout << "Value is " << x << endl;
}

int main() {
  int x = 42;
  disp(x);
  x = doubleIt(x);
  disp(x);
}

