#include <GameRec.h>
#include <iostream>

using namespace std;

const char STRIKE = 'X';
const char SPARE = '/';

GameRec::GameRec() {
}
  
GameRec::~GameRec() {
  // Nothing to do.
}

int GameRec::getCurrentScore() {
  if (!isComplete()) {
    // The recursive scorer only works on complete games
    return -1;
  }
  return score(rolls, 0, 1);
}

bool GameRec::isSpare(char ch) {
  return ch == SPARE;
}

bool GameRec::isStrike(char ch) {
  return ch == STRIKE;
}

int GameRec::pinValue(char ch) {
  if (isSpare(ch) || isStrike(ch)) {
    return 10;
  }
  return ch - '0';
}

int GameRec::score(vector<char> &rolls, int startingAt, int frame) {
  // Base cases. there are lots of them since this special cases all of the different
  // 10th frame scenarios that might exist  
  const int rollsLeft = rolls.size() - startingAt;
  if (rollsLeft <= 1) {
    return 0;
  }
  if (frame == 10 && rollsLeft == 3 && isSpare(rolls[startingAt + 1])) {
    return 10 + pinValue(rolls[startingAt + 2]);
  }
  if (frame == 10 && rollsLeft == 3 && isStrike(rolls[startingAt]) && isStrike(rolls[startingAt + 1]) && isStrike(rolls[startingAt + 2])) {
    return 30;
  }
  if (frame == 10 && rollsLeft == 3 && isStrike(rolls[startingAt]) && isStrike(rolls[startingAt + 1])) {
    return 20 + pinValue(rolls[startingAt + 2]);
  }
  if (frame == 10 && rollsLeft == 3 && isStrike(rolls[startingAt]) && isSpare(rolls[startingAt + 2])) {
    return 20;
  }
  if (frame == 10 && rollsLeft == 3 && isStrike(rolls[startingAt])) {
    return 10 + pinValue(rolls[startingAt + 1]) + pinValue(rolls[startingAt + 2]);
  }
  if (rollsLeft == 2) {
    return pinValue(rolls[startingAt]) + pinValue(rolls[startingAt + 1]);
  }
  // Done with base cases, look at the different recurrence relationships.
  // Spares
  if (isSpare(rolls[startingAt+1]) && isStrike(rolls[startingAt+2])) {
    return 20 + score(rolls, startingAt + 2, frame + 1);
  }
  if (isSpare(rolls[startingAt+1])) {
    return 10 + pinValue(rolls[startingAt+2]) + score(rolls, startingAt + 2, frame + 1);
  }
  // Strikes
  if (isStrike(rolls[startingAt]) && isSpare(rolls[startingAt + 2])) {
    return 20 + score(rolls, startingAt + 1, frame + 1);
  }
  if (isStrike(rolls[startingAt]) && isStrike(rolls[startingAt + 1]) && isStrike(rolls[startingAt + 2])) {
    return 30 + score(rolls, startingAt + 1, frame + 1);
  }
  if (isStrike(rolls[startingAt]) && isStrike(rolls[startingAt + 1])) {
    return 20 + pinValue(rolls[startingAt + 2]) + score(rolls, startingAt + 1, frame + 1);
  }
  if (isStrike(rolls[startingAt])) {
    return 10 + pinValue(rolls[startingAt + 1]) + pinValue(rolls[startingAt + 2]) + score(rolls, startingAt + 1, frame + 1);
  }
  return pinValue(rolls[startingAt]) + pinValue(rolls[startingAt + 1]) + score(rolls, startingAt + 2, frame + 1);
}
