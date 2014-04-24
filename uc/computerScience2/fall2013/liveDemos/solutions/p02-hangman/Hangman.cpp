/**
 * @author Mike Helmick - mike.helmick@uc.edu
 *
 * Implementation for the Hangman class.
 */
#include <Hangman.h>

#include <string>
#include <iostream>

using namespace std;

// Static constant for the hangman class, only needs to exist once.
const char Hangman::UNDERSCORE = '_';

Hangman::Hangman(const string& word) : targetWord(word) {
  missesRemaining = 6;
  commonInit();
}

Hangman::Hangman(const string& word, int guessesAllowed) : targetWord(word), missesRemaining(guessesAllowed) {
  commonInit();
}

Hangman::Hangman() {
  // private, not used
}

void Hangman::commonInit() {
  currentState = "";
  while (currentState.size() != targetWord.size()) {
    currentState += UNDERSCORE;
  }
}

Hangman::~Hangman() {
  // nothing to do here
}

bool Hangman::isGameOver() const {
  return isWinner() || missesRemaining == 0;
}

int Hangman::getMissesRemaining() const {
  return missesRemaining;
}

string Hangman::getIncorrectGuesses() const {
  return incorrectGuesses;
}

bool Hangman::isWinner() const {
  return currentState == targetWord;
}

void Hangman::guessLetter(char guess) {
  // Do not accept guesses if the game is over.
  if (isGameOver()) {
    return;
  }
  
  // check for valid char, return if it is not.
  if (guess < 'a' || guess > 'z') {
    return;
  }
  
  // see if the letter has already been guessed, return if it has
  if (incorrectGuesses.find_first_of(guess) != string::npos
      || currentState.find_first_of(guess)  != string::npos) {
    return;      
  }

  // See if this is a miss, or a hit.
  if (targetWord.find_first_of(guess) == string::npos) {
    // This is a miss
    missesRemaining--;
    incorrectGuesses += guess;
  } else {
    // Hit - update current state
    string newState = "";
    for (unsigned int i = 0; i < targetWord.size(); i++) {
      if (targetWord[i] == guess) {
        newState += guess;
      } else {
        newState += currentState[i];
      }
    }
    currentState = newState;
  }
}

string Hangman::getTargetWord() const {
  return targetWord;
}

string Hangman::getCurrentDisplay() const {
  return currentState;
}
