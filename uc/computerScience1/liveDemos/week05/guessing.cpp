#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
  srand(time(NULL));

  int target = rand() % 100 + 1;
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
  return 0;
}

