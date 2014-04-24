// overloading.cpp
#include <iostream>
using namespace std;

void printNumbers(int a) {
  cout << "Number: " << a << endl;
}

void printNumbers(int a, int b) {
  printNumbers(a);
  printNumbers(b);
}

int main() {

  printNumbers(100);

  printNumbers(200, 300);

}

