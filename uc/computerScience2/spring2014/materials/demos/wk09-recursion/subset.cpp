#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> subsets(string word){
  vector<string> ret;
  if(word.size() == 1){
    ret.push_back(word);
    ret.push_back("");
    return ret;
  }
  char c = word[0];
  string rest = word.substr(1);
  
  vector<string> rests = subsets(rest);
  for(int i = 0; i < rests.size(); i++){
    string sub =rests[i];
    ret.push_back(c + sub);
    ret.push_back(sub);
  }
  return ret;
}

int main(int argc, char* argv[]){
if(argc != 2){
    cout << "Enter your word on the command line.\n";
    return 0;
  }
  string word = argv[1];
  vector<string> subs = subsets(word);
  cout << "Number of subsets for '" << word << "' is: " << subs.size() << endl;
  for(unsigned int i = 0; i < subs.size(); i++){
    cout << subs[i] << endl;
  }
}