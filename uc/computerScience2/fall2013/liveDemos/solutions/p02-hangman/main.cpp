/**
 * @author Mike Helmick - mike.helmick@uc.edu
 *
 * Main program for the hangman game. Plays as many games as the user wants, with
 * the wordswithfriends dictionary file.
 */
#include <Hangman.h>
#include <Dictionary.h>

#include <iostream>

int main() {
  Dictionary dict("wordswithfriends.txt");
  cout << "Welcome to Hangman (beta). I've loaded " << dict.getWordCount() << " words." << endl;
  
  bool playing = true;
  while (playing) {
    cout << "--------------------------------------------------------------------------------" << endl;
    Hangman hm(dict.getRandomWord());

    char guess;
    while (!hm.isGameOver()) {
      cout << "Guess: " << hm.getCurrentDisplay() << "  misses remaining: " << hm.getMissesRemaining()
          << " missed letters: " << hm.getIncorrectGuesses() << endl;
      cin >> guess;
      hm.guessLetter(guess);
    }

    if (hm.isWinner()) {
      cout << "You win! You guessed the word: " << hm.getTargetWord() << " with " << hm.getMissesRemaining() << " misses remaining." << endl;
    } else {
      cout << "Sorry, you lost. The word was: " << hm.getTargetWord() << endl;
    }

    cout << "Play again? (Y/n)?";
    cin >> guess;
    if (guess == 'n') {
      playing = false;
    }
  }
  cout << "Goodbye, thanks for playing." << endl;
  
  return 0;  
}
