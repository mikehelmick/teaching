#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverse(string word){
  if(word.size() <= 1){
    return word;
  }
  return reverse(word.substr(1)) + word[0];
}

int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Enter your word on the command line.\n";
    return 0;
  }
  string word = argv[1];
  string rev = reverse(word);
  cout << word << " reversed is " << rev << endl;
}