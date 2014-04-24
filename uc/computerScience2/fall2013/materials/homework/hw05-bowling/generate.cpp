/**
 * generate.cpp - 
 * Generates a whole bunch of valid bowling games at random.
 */
#include <Game.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <cstdlib>

using namespace std;

char roll(Game &g) {
  bool strikeAllowed =
      (g.getCurrentFrame() <= 9 && g.getCurrentRoll() == 1)
      || (g.getCurrentFrame() == 10
          && (g.getCurrentRoll() == 1
              || (g.getCurrentRoll() == 2 && g.getLastRoll() == 'X')
              || (g.getCurrentRoll() == 3 && (g.getLastRoll() == 'X' || g.getLastRoll() == '/'))));
  int limit = 10;
  if (!strikeAllowed) {
    limit = 10 - (g.getLastRoll() - '0');
  }
  int randVal = rand() % 11;
  
  if (randVal == 10) {
    if (strikeAllowed) {
      return 'X';
    } else {
      return '/';
    }
  }
  // Handle number rolls
  if (randVal >= limit) {
    return '/';
  }
  // Not a spare, just a number roll
  return randVal + '0';
}

int main() {
  srand(time(NULL)); 

  for (int i = 0; i < 10000; i++) {
    Game g;
    while (!g.isComplete()) {
      if (g.getCurrentFrame() > 1 || g.getCurrentRoll() == 2) {
        cout << ' ';
      }      
      char curRoll = roll(g);
      cout << curRoll;
      g.addRoll(curRoll);
    }
    cout << endl;
  }
}
