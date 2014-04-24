#include <iostream>
using namespace std;

const string SECRET_WORD = "secret";

int main() {
  cout << "Can you guess the secret word? ";
  string word;
  cin >> word;

  if (word == SECRET_WORD) {
    cout << "You guessed it!" << endl;
  } else if (word < SECRET_WORD) {
    cout << "Your word comes before the secret word" << endl;
  } else {
    cout << "Your word comes after the secret word" << endl;
  }
  
}