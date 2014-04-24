#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> permute(string word){
  vector<string> ret;
  // Can't permute a single character!
  if(word.size() <= 1){
    ret.push_back(word);
    return ret;
  }
  // Take the first character off, and then place it everywhere possible
  char first = word[0];
  vector<string> rests = permute( word.substr(1));
  for(int j = 0; j < rests.size(); j++){ //For each of the permutations
    string thisword = rests[j];
    for(int i = 0; i <= thisword.size(); i++){ // put the char between each 
      string left = thisword.substr(0,i);
      string right = thisword.substr(i);
      ret.push_back(left + first + right);
    }
  }
  return ret;
}

int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Enter your word on the command line.\n";
    return 0;
  }
  string word = argv[1];
  vector<string> perms = permute(word);
  cout << "Number of permutations for '" << word << "' is: " << perms.size() << endl;
  for(unsigned int i = 0; i < perms.size(); i++){
    cout << perms[i] << endl;
  }
}