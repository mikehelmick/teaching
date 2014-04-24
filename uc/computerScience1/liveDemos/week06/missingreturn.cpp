#include <iostream>
using namespace std;

int doubleIt(int x) {
  x =  x * 2;
  double var = x * x * x * x * x;
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
