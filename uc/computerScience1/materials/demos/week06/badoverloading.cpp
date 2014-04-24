// badoverloading.cpp
#include <iostream>
using namespace std;

int printNumbers(int val) {
  cout << "Int: " << val << endl;
}

float printNumbers(int val) {
  cout << "Int2: " << val << endl;
}

void printNumbers(double val) {
  cout << "Double: " << val << endl;
}


int main() {

  int intVal = 5;
  float floatVal = 5.5f;
  double doubleVal = 5.5;

  printNumbers(intVal);
  printNumbers(floatVal);
  printNumbers(doubleVal);

}
