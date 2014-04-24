#include <iostream>
#include <string>
using namespace std;

void fun(int i) {
  cout << "called int version" << endl;
}

int fun(double i) {
  cout << "called double version" << endl;
}

int main() {
  fun(2);
  fun(3);
  fun(2.0);
  fun(3.0);
}
