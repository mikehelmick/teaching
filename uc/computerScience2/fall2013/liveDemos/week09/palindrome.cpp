/*
 * palindrome.cpp
 * Paul Talaga
 * 
 * Returns true if the given word is a palindrome, false otherwise
 * Oct 22 , 2013
 */

#include <iostream>
#include <cstdlib>

using namespace std;

bool palen(string s){
  if(s.size() <= 1){    // Base case.  A 0 or 1 character string is a palindrome.
    return true;
  }
  char f = s[0];        // Save the first and second characters
  char l = s[s.size()-1];
  string middle = s.substr(1,s.size()-2); // Save the middle
  if(f != l){ // If the first and last aren't the same, don't recuse, just return false.
    return false;
  }
  return palen(middle); // Recuse on a shorter (by 2) string
}

int main(int argc, char* argv[]){
  if(argc <= 1){
    cout << "Give me a word!\n";
    return 0;
  }
  string a = argv[1];

  cout << "Is " << a << " a palindrome?: " << palen(a) << endl;
  return 0;
}