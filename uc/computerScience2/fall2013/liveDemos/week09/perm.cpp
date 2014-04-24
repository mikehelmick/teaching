/*
 * perm.cpp
 * Paul Talaga
 * 
 * Prints out all permutations of the given string, as well as how many there are.
 * Should be n! where n is the length of the string.
 * Oct 22 ,2013
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> perm(string s){  // Return a vector of strings
  vector<string> ret;           // The return vector
  if(s.size() == 1){            // Base case, the permutation of 1 character is that
    ret.push_back(s);           // character (string).
    return ret;
  }
  for(int i =0; i < s.size(); i++){ // For each letter in the input string,
    char f = s[i];                  // that will start the same # of permutations
    string others = s.substr(0,i) + s.substr(i+1);  // Save the 'other' letters
    vector<string> perms = perm(others);  // Find all permutations of 'other' letters
    for(int j = 0; j < perms.size() ; j++){ // Loop through all perms of 'other'
      ret.push_back(f + perms[j]);          // and tack on the character we removed
    }
  }
  return ret;                   // Return the vector of strings
}

int main(int argc, char* argv[]){
  if(argc <= 1){
    cout << "Give me a word!\n";
    return 0;
  }
  string a = argv[1];
  vector<string> r = perm(a);
  cout << "Perms of " << a << ": " << endl;
  cout << "There are " << r.size() << endl;
  for(int i = 0; i < r.size() ; i ++){
    cout << r[i] << endl;
  }
  return 0;
}