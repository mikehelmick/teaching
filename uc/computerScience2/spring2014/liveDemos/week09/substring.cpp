/*
 * Substring search - how many occurances of a given pattern
 * appear in a string
 */

#include <iostream>
#include <string>
using namespace std;

int subSearch(string needle, string haystack) {
  if (needle.size() > haystack.size()) {
    return 0;
  }

  // The rest of the haystack, everything but the first character.
  int found = 1;
  for (int i = 0; i < needle.size(); i++) {
    if (needle[i] != haystack[i]) {
      found = 0;
      break;
    }
  }
  // We know that we found a match starting at the first character
  // in the current haystack.
  int chopAt = 1;
  if (found > 0) {
    chopAt = needle.size();
  }
  string bale = haystack.substr(chopAt);
  return found + subSearch(needle, bale);
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Give me two words.\n";
    return 0;
  }
  string a = argv[1];
  string b = argv[2];

  cout << "How many " << a << " in " << b << " ?" << endl;
  cout << subSearch(a, b) << endl;
  return 0;
}
