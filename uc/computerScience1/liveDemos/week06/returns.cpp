#include <iostream>
using namespace std;

void printIfEven(int val) {
  if (val % 2 != 0) {
    return;
  }

  cout << val << " is even" << endl;
}

int doubleIt(int val) {
  return val * 2;
}

int main() {

  printIfEven(5);
  printIfEven(6);

  int x = 12;
  printIfEven(x);
  x = doubleIt(x);
  printIfEven(x); 
}
