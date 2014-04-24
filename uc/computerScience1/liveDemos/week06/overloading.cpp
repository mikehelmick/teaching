#include <iostream>
#include <string>
using namespace std;

void printNumbers(int a) {
  cout << "The int version " << endl;
}

void printNumbers(string a) {
  cout << "The string version " << endl;
}

int main() {
  printNumbers(100);
  printNumbers("100");
}
