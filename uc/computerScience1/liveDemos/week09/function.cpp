// Example 13 - function.cpp
#include <iostream>
#include <string>
using namespace std;

/*
 * Allocates and returns a pointer to
 * a new string. The caller owns the 
 * memory returned.
 */
string* getWord() {
  cout << "Enter a word: ";
  string* word = new string();
  cin >> *word;
  return word;
}

int main() {
  for (int i = 0; i < 2; i++) {
    string* word = getWord();
    cout << "You entered: " << *word << endl;
    
    // Delete is required, otherwise memory leak
    delete word;
  }
}

