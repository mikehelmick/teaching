/**
 * Recursive detection of a palindrome.
 */

#include <iostream>
#include <string>
using namespace std;

bool palen(string s) {
  // Base case, strings of size zero or 1 are 
  // always palindromes.
  if (s.size() <= 1) {
    return true;
  }

  char f = s[0];
  char l = s[s.size() - 1];
  if (f != l) {
    return false;
  }
  string middle = s.substr(1, s.size() - 2);
  return palen(middle);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "I require a string." << endl;
    return 0;
  }
  string a = argv[1];

  cout << "Is " << a << " a palindrome?: " << palen(a) << endl;
  return 0;
}
