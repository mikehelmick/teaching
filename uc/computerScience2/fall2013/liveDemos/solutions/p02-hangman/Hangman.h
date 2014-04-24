/**
 * @author Mike Helmick - mike.helmick@uc.edu
 *
 * Interface for a class that plays a single game of Hangman.
 */
#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
using namespace std;

class Hangman {
public:
  /** Create a game w/ the default, 6, misses allowed */
  Hangman(const string& word);
  /** Cretes a game with a customer number of misses allwoed */
  Hangman(const string& word, int guessesAllowed);
  virtual ~Hangman();

  /** @return true if the game is complete, with either a win or a loss */
  bool isGameOver() const;
  /** @return number of incorrect gesses before a lost occurs */
  int getMissesRemaining() const;
  /** @return true, if the player has won the game */
  bool isWinner() const;

  /** Guesses the letter passed in, the guess may be disregarded if it is not
   * a lowecase letter, or has been guessed previously.
   */
  void guessLetter(char guess);
  /** @return a string of the incorrect letters guessed */
  string getIncorrectGuesses() const;

  /** @return the word attempting to be guessed */
  string getTargetWord() const;
  /** @return the word with underscore (_) characters and correctly guessed letter */
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
