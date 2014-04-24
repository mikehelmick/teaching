// ignorereturn.cpp
#include <iostream>
using namespace std;

int doubleIt(int i) {
  return i * 2;
}

int main() {

  int x = 42;
  cout << "x is " << x << endl;
  doubleIt(x);
  cout << "2 * x is " << x << endl;

}
