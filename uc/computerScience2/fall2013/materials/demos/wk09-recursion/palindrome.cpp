#include <iostream>
#include <string>

using namespace std;

bool palindrome(string word){
  if(word.size() <= 1){
    return true;
  } 
  char first = word[0];
  char last = word[word.size()-1];
  string middle = word.substr(1,word.size()-2);
  return first == last && palindrome(middle);
}

int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Enter your word on the command line.\n";
    return 0;
  }
  string word = argv[1];
  cout << word << " is a palindrome? " << palindrome(word) << endl;
}