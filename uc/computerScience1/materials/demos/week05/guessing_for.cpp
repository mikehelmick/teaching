// week05/guessing_for.cpp

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  srand(time(NULL));
  
  int target = rand() % 100 + 1;
  int guess = 0;
  
  for (int guesses = 1; guess != target; guesses++) {
    cout << "Guess #" << setw(3) << guesses
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