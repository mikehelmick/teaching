/*
 * recursively reverse a string
 */
#include <iostream>
#include <string>
using namespace std;

string rev(string s, int calls) {
  // Base case - strings of size zero and one
  // are the reverse of themselves by definition.
  if (s.size() == 0 || s.size() == 1) {
    cout << "rev calls: " << calls << endl;
    return s;
  }

  char first = s[0];
  char last = s[s.size() - 1];
  string middle = s.substr(1, s.size() - 2);

  return last + rev(middle, calls + 1) + first;
}

string rev2(string s, int calls) {
  if (s.size() == 0) {
    cout << "rev2 calls: " << calls << endl;
    return "";
  }

  char first = s[0];
  string middle = s.substr(1, s.size() - 1);
  return rev2(middle, calls + 1) + first;
}

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    cout << "Give me a string." << endl;
    return 0;
  }

  string s = argv[1];
  cout << "Reverse of " << s << " is: " << rev(s, 1) << endl;
  cout << "Reverse of " << s << " is: " << rev2(s, 1) << endl;
  return 0;
}
