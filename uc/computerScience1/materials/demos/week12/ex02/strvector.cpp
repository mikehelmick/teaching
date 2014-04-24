// Example 02 - VEctor of Strings
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getString() {
  cout << "Enter a string: ";
  string str;
  cin >> str;
  return str;
}

int main() {

  vector<string> myStrings;
  for (int i = 0; i < 5; i++) {
    myStrings.push_back(getString());
  }

  for (int i = 0; i < 5; i++) {
    cout << "i=" << i << " :: " << myStrings[i] << endl;
  }
}
