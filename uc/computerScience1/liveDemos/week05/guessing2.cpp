#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
  srand(time(NULL));

  bool keepPlaying = true;

  while (keepPlaying) {
    int target = rand() % 10 + 1;
    int guesses = 0;
    int guess = 0;

    while (guess != target) {
      cout << "Guess #" << setw(3) << (++guesses)
          << ": Guess a number between 1 and 100: ";
      cin >> guess;
      if (guess > target) {
        cout << "lower" << endl;
      } else if (guess < target) {
        cout << "higher" << endl;
      } 
    }
    cout << "You got it! The secret number is " << target << endl;

    cout << endl << "Do you want to play again? (y/n): ";
    char answer;
    cin >> answer;
    while (!(answer == 'y' || answer == 'n')) {
       cout << "Please enter y or n. Do you want to play again? (y/n:) ";
       cin >> answer;
    }
    // What do I know here?
    keepPlaying = answer == 'y'; 
  }
  cout << "Goodbye." << endl;
  return 0;
}

