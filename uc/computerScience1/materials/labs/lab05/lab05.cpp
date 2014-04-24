#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

// Returns a random die roll from 1 through 6 (inclusive)
int rollDie() {
  return rand() % 6 + 1;
}

/**
 * Given the player's account balance, this function will
 * ask for, and accept a valid awger.
 */
int getWager(int balance) {
  cout << "Account balance $" << balance << endl;
  cout << "Enter wager (0 to exit): ";
  int wager;
  cin >> wager;
  
  while (wager < 0 || wager > balance) {
    cout << "Error: You must wager between $1 and $" << balance << " (type 0 to exit): ";
    cin >> wager;
  }
  return wager;
}

/**
 * Handles the game play for a singel game (pick point, roll up to 3 times).
 * Returns true if the player wins, false if the player loses. This method
 * does not in any way handle the account balance or wagers.
 */
bool playOneGame() {
  cout << endl << "Enter your point value (1 - 6): ";
  int point;
  cin >> point;
  
  while (point < 1 || point > 6) {
    cout << "Error: Enter your point value, must be between 1 and 6: ";
    cin >> point;
  }

  int roll = 0;
  for (int i = 1; i <= 3 && roll != point; i++) {
    roll = rollDie();
    cout << "Roll #" << i << " is " << roll << endl;
  }
  if (roll == point) {
    cout << " ** You win! **" << endl;
  } else {
    cout << " ** You Lose **" << endl;
  }
  return roll == point;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Starting account balance of $100  
  int balance = 100;

  // Loop forever (until quit)
  while (true) {
    // Get a valid wager, based on account balance.
    int wager = getWager(balance);
    // Sentinel value, quit.
    if (wager == 0) {
      break;
    }
  
    if (playOneGame()) {
      // Player wins
      balance += wager;
    } else {
      // Player loses
      balance -= wager;
      if (balance == 0) {
        // Player lost and is out of money...
        cout << "Game over, you are out of money!" << endl;
        break;
      }
    }
  }
  
  cout << "Your final account balance is $" << balance << endl;  
  return 0;
}