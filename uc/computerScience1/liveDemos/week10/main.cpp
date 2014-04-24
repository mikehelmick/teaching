// Hangman
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<string> loadDictionary() {
  ifstream inFile;
  inFile.open("wordswithfriends.txt");

  vector<string> allWords;

  string emptyString("");
  while (!inFile.eof()) {
    string line;
    getline(inFile, line);
    if (line != emptyString) {
      allWords.push_back(line);
    }
  }

  return allWords;
}

string initGuess(const string &targetWord) {
  string rtn = "";
  for (int i = 0; i < targetWord.size(); i++) {
    rtn += "_";
  }
  return rtn;
}

bool beenGuessedBefore(string guessed, char ch) {
  for (int i = 0; i < guessed.size(); i++) {
    if (guessed[i] == ch) {
      return true;
    }
  }
  return false;
}

char guessLetter(string &letterGuessed) {
  cout << "Guess: ";
  char ch;
  cin >> ch;
  while (ch < 'a' || ch > 'z' || beenGuessedBefore(letterGuessed, ch)) {
    cout << "Please enter a-z and not guessed already: ";
    cin >> ch;
  }
  letterGuessed += ch;
  return ch;
}

bool adjustWordInProgress(string &wordInProgress,
    const string &targetWord, char nextGuess) {
  bool matchedAny = false;
  for (int i = 0; i < targetWord.size(); i++) {
    if (targetWord[i] == nextGuess) {
      wordInProgress[i] = nextGuess;
      matchedAny = true;
    }
  }
  return matchedAny;
}

int main() {
  srand(time(NULL));
  vector<string> allWords = loadDictionary();
  cout << "Loaded " << allWords.size()
      << " words." << endl;

  string targetWord = allWords[rand() % allWords.size()];
  string lettersGuessed;
  string wordInProgress = initGuess(targetWord);
  int missesLeft = 5;

  while (missesLeft > 0 && wordInProgress != targetWord) {
    cout << "Guess: " << wordInProgress << endl;
    char nextGuess = guessLetter(lettersGuessed);
    if (adjustWordInProgress(wordInProgress, targetWord, nextGuess)) {
      cout << "You got a letter right" << endl;
    } else {
      cout << "Ouch! You missed one." << endl;
      missesLeft--;
    }
  }

  if (missesLeft > 0) {
    cout << "You win!" << endl;
  }
  cout << "word: " << targetWord << endl;

  return 0;
}
