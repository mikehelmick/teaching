#include <iostream>
#include <string>
#include <vector>

using namespace std;

int substrings(string needle, string haystack){
  if(haystack.size() < needle.size()){
    return 0;
  }
  string next = haystack.substr(1);
  for(int i = 0; i < needle.size(); i++){
    if(needle[i] != haystack[i]){
      return substrings(needle, next);  // not a match, keep searching
    }
  }
  // must have found it!
  return substrings(needle, next) + 1;
}

int main(int argc, char* argv[]){
  if(argc != 3){
    cout << "Enter your words on the command line.   ./a.out needle haystack\n";
    return 0;
  }
  string needle = argv[1];
  string haystack = argv[2];
  string haystack;
  cin >> haystack;
  cout << "Found '" << needle << "' in the haystack " << substrings(needle, haystack) << " times\n";
}