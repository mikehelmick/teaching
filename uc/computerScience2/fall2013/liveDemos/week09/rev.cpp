/*
 * rev.cpp
 * Paul Talaga
 * 
 * Reverses a given string using recursion.
 * Oct 21 , 2013
 */
#include <iostream>
#include <string>

using namespace std;


string rev(string s){
  if(s.size() == 0){      // Base case, reverse of "" is ""
    return "";  
  }else if(s.size() ==1){ // Base case, reverse of a 1 letter string is that letter
    return s;             // Since we're shortening our string by 2 each time (see below)
  }                       // we need to make sure we 'catch' both possibilities.
  char first = s[0];
  char last = s[s.size()-1];
  string middle = s.substr(1,s.size()-2);
  
  return last + rev(middle) + first;    // Flip first and last characters, then put that with
}                                       // the reverse of the middle.


/*
 *  Alternate version of reverse that only takes off the fist character.
 *  Doesn't need 2 base cases since we're shortening by 1 each time.
 */
string rev2(string s){
  if(s.size() == 0){      // Base case, reverse of "" is ""
    return "";  
  }                     
  char first = s[0];
  string middle = s.substr(1,s.size()-1);
  
  return rev(middle) + first;   // Put the first character on the end, and reverse the rest.    
}                                       


int main(int argc, char* argv[]){
  if(argc <= 1){
    cout << "Give me a string.\n";
    return 0;
  }
  string s = argv[1];
  cout << "Reverse of " << s << " is: " << rev2(s) << endl;

  return 0;
}