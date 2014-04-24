#include "MyClass.h"

#include <iostream>
using namespace std;

int x = 7;

int main() {
  MyClass y(5);
  cout << "getX returns " << y.getX() << endl;
}