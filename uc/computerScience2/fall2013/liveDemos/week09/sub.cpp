/*
 * sub.cpp
 * Paul Talaga
 * 
 * Prints all substrings of the given string.
 * Oct 22 ,2013
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

vector<string> subs(string s){
  vector<string> ret;
  if(s.size() == 0){
    ret.push_back(s);
    return ret;
  }
  string rest = s.substr(1);
  char f = s[0];
  vector<string> su = subs(rest);
  for(int j = 0; j < su.size() ; j++){
    ret.push_back(f + su[j]);
    ret.push_back(su[j]);
  }

  
  //
  return ret;
}

int main(int argc, char* argv[]){
  if(argc <= 1){
    cout << "Give me a word!\n";
    return 0;
  }
  string a = argv[1];
  vector<string> r = subs(a);
  cout << "Perms of " << a << ": " << endl;
  cout << "There are " << r.size() << endl;
  for(int i = 0; i < r.size() ; i ++){
    cout << r[i] << endl;
  }
  return 0;
}