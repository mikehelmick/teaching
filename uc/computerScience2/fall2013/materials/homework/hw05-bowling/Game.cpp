#include <Game.h>
#include <iostream>

using namespace std;

const char STRIKE = 'X';
const char SPARE = '/';

Game::Game() {
  // rolls vector doesn't need to be initialized, the constructor is called for us.
  currentFrame = 1;
  currentRoll = 1;
  gameComplete = false;
  bonusRollAwarded = false;
}
  
Game::~Game() {
  // Nothing to do.
}

void Game::debug() {
  cout << "score: " << getCurrentScore() << " frame: " << currentFrame << " roll: " << currentRoll
      << " complete: " << gameComplete << " bonus: " << bonusRollAwarded << endl;
  for (unsigned int i = 0; i < rolls.size(); i++) {
    cout << " " << rolls[i];
  }
  cout << endl;
}

bool Game::addRoll(char ch) {
  if (gameComplete) {
    return true;
  }

  rolls.push_back(ch);
  if (ch == STRIKE) {
    if (currentFrame == 10) {
      if (currentRoll == 1) {
        bonusRollAwarded = true;
        currentRoll++;
      } else if (currentRoll == 2) {
        // move on to third role
        currentRoll++;
      } else if (currentRoll == 3) {
        // Therefore game complete
        gameComplete = true;
      }
    } else {
      currentFrame++;
      currentRoll = 1; // Sholdn't be necessary
    }
  } else if (ch == SPARE) {
    if (currentFrame == 10 && currentRoll == 2) {
      bonusRollAwarded = true;
      currentRoll = 3;
    } else if (bonusRollAwarded) {
      gameComplete = true;
    } else {
      currentFrame++;
      currentRoll = 1;
    }
  } else {
    currentRoll++;
    if ((bonusRollAwarded && currentRoll >= 4) || (!bonusRollAwarded && currentRoll >= 3)) {
      currentFrame++;
      currentRoll = 1;
    }
    if (currentFrame == 11) {
      currentFrame = 10;
      gameComplete = true;
    }
  }
  return gameComplete;
}

int Game::getPinValueAtPosition(const unsigned int &pos) {
  if (rolls[pos] == STRIKE || rolls[pos] == SPARE) {
    return 10;
  }
  return rolls[pos] - '0';
}

int Game::getCurrentScore() {
  int score = 0;
  int rollLimit = rolls.size();
  // Check for 10th frame oddities.
  if (gameComplete && bonusRollAwarded) {
    // In this case, we need to not double count one or both of the last rolls
    if (rolls[rollLimit - 3] == STRIKE) {
      // Strike to start 10th frame, don't double count last two rolls
      rollLimit = rollLimit - 2;
    } else {
      // Must be a spare in the 10th, otherwise bonus roll wouln't have been awarded.
      rollLimit = rollLimit - 1;
    }
  }
  
  // Score each roll, acconuting for open marks.
  for (unsigned int i = 0; i < rollLimit; i++) {
    if (rolls[i] == STRIKE) {
      if (i + 2 >= rolls.size()) {
        // Strike cannot be calculated yet.    
        return score;
      } else {
        if (rolls[i+2] == SPARE) {
          // 2 rolls out is a spare, so skip i+1
          score += getPinValueAtPosition(i) + getPinValueAtPosition(i + 2);
        } else {
          score += getPinValueAtPosition(i) + getPinValueAtPosition(i + 1) + getPinValueAtPosition(i + 2);       
        }
      }
    } else if (rolls[i] == SPARE) {
      if (i + 1 >= rolls.size()) {
        // spare cannot be calculated yet, but we also need to subtract off the previous roll
        return score - getPinValueAtPosition(i - 1);
      } else {
        // Subtract previous roll, it is included in the spare
        score = score - getPinValueAtPosition(i - 1) + getPinValueAtPosition(i) + getPinValueAtPosition(i + 1);        
      }
    } else {
      // Filter out fill roll(s)
      if (bonusRollAwarded && i >= rolls.size() - 2
          && ((rolls[rolls.size()-3] == STRIKE) || (rolls[rolls.size() - 2] == SPARE))) {
        // This is a numerical bonus roll, it should just be filtered out.
        // No-op.
      } else {
        score += getPinValueAtPosition(i);
      }
    }
  }
  return score;
}

int Game::getCurrentFrame() {
  return currentFrame;
}

int Game::getCurrentRoll() {
  return currentRoll;
}

bool Game::isComplete() {
  return gameComplete;
}

int Game::getPinsKnockedDown() {
  int totalPins = 0;
  for (unsigned int i = 0; i < rolls.size(); i++) {
    if (rolls[i] == STRIKE) {
      totalPins += getPinValueAtPosition(i);
    } else if (rolls[i] == SPARE) {
      totalPins = totalPins - getPinValueAtPosition(i-1) + getPinValueAtPosition(i);
    } else {
      totalPins += getPinValueAtPosition(i);
    }
  }
  return totalPins;
}

int Game::getStrikesThrown() {
  int strikeCount = 0;
  for (vector<char>::iterator it = rolls.begin(); it != rolls.end(); it++) {
    if (*it == STRIKE) {
      strikeCount++;
    }
  }
  return strikeCount;
}

int Game::getRollCount() {
  return rolls.size();
}

char Game::getLastRoll() {
  return rolls[rolls.size() - 1];
}
