#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
using namespace std;

class Hangman {
public:
  Hangman(const string& word);
  Hangman(const string& word, int guessesAllowed);
  virtual ~Hangman();

  bool isGameOver() const;
  int getMissesRemaining() const;
  bool isWinner() const;

  void guessLetter(char guess);
  string getIncorrectGuesses() const;

  string getTargetWord() const;
  string getCurrentDisplay() const;

private:
  static const char UNDERSCORE;
  
  const string targetWord;
  string currentState;
  string incorrectGuesses;

  int missesRemaining;
  
  void commonInit();
  Hangman();
};

#endif
