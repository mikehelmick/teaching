#include <iostream>
using namespace std;

int printNumbers(int val) {
  cout << "int, int version" << endl;
}

float printNumbers(int val) {
  cout << "float, int version" << endl;
}

void printNumbers(double val) {
  cout << "void, double version" << endl;
}

int main() {
  int intVal = 5;
  float floatVal = 5.5f;
  double doubleVal = 5.5;

  printNumbers(intVal);
  printNumbers(floatVal);
  printNumbers(doubleVal);  
}
