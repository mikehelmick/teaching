#include <iostream>
#include <string>
using namespace std;

void printMessage(const string &message) {
  cout << "&message = " << &message << " :: " << message << endl;

  // ERROR - Can't change, because this is a const reference
  //message += "This is awesome!";
}

int main() {
  string hello = "Hello, world!";

  cout << "&hello = " << &hello << " :: " << hello << endl;
  printMessage(hello);

  return 0;
}
