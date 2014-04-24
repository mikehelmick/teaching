#include <iostream>

using namespace std;

int myFun(int x) {
  if (x % 100 == 0) {
    cout << "x = " << x << endl;
  }
  myFun(x + 1);
}

int main() {
  int y = myFun(1);
}