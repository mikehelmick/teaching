/*
 * substring.cpp
 * Paul Talaga
 * 
 * Given a needle and haystack, prints out how many times
 * needle is in haystack.
 * Oct 22 ,2013
 */

#include <iostream>
#include <string>

using namespace std;

int sub(string needle, string haystack){
  if(haystack.size() < needle.size()){  // Base case.  If haystack is too short for
    return 0;                           // needle, return 0, since there isn't any matches.
  }
  string bale = haystack.substr(1);   // The 'rest' of the haystack after a char off
  // Check to see if needle is on the front of haystack
  for(int i = 0; i < needle.size();i++){
    if(needle[i] != haystack[i]){     // If a character doesn't match, continue on
      return sub(needle, bale);       // with a shorter haystack.
    }
  }
  // needle found!  Add 1 to the however many needles found further down.
  return sub(needle, bale) + 1;
}

int main(int argc, char* argv[]){
  if(argc <= 2){
    cout << "Give me two  words!\n";
    return 0;
  }
  string a = argv[1];
  string b = argv[2];
  cout << "How many '" << a << "' in '" << b << "': " << sub(a,b) << endl;
  return 0;
}