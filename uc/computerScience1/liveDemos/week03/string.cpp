#include <iostream>
#include <string>

using namespace std;

int main() {
  string greeting = "Hello";
  string name = "Steve";

  // Example of + operator to join strings
  string welcome = greeting + ", " + name + "!";
  cout << welcome << endl;
  cout << "Length of message: " << welcome.length() << endl;

  for (int i = 0; i <= 1000000*welcome.length(); i++) {
    cout << welcome[i] << endl;
  }

  return 0;
}
