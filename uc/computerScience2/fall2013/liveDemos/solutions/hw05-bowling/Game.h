#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
using namespace std;

class GameTest;

class Game {
public:
  /** Default constructor. Initializes an empty game.
    */
  Game();

  /** Destructor */
  virtual ~Game();

  /** Adds a single role to the game. Returns true if the game is now complete,
   * otherwise false is returned */
  bool addRoll(char ch);

  /** Returns the current score, based on what can be calculated.
   * If the trailing spare or strike can't be completly calculated yet, 
   * it isn't included
   */
  virtual int getCurrentScore();

  /** Gets the current frame number
   */
  int getCurrentFrame();

  /** Gets the current roll in the current frame
   */
  int getCurrentRoll();

  /** Returns true if the game is complete, false otherwise
   */
  bool isComplete();

  /**
   * Returns the total number of pins knocked down in the game. This is
   * different from the score!
   */
  int getPinsKnockedDown();

  /**
   * Returns the numbe of strikes thrown.
   */
  int getStrikesThrown();

  /** Returns the number of rolls
   */
  int getRollCount();

  char getLastRoll();

protected:
  // Contains the raw value of the rolls
  vector<char> rolls;
  // The current frame that you are in (1 - 10)
  int currentFrame;
  // The current roll for the frame that you are in (1-2)
  int currentRoll;
  // Tracks if the game is complete or not
  bool gameComplete;
  // Was there a bonus roll awarded in the 10th frame?
  bool bonusRollAwarded;

  virtual void debug();

  int getPinValueAtPosition(const unsigned int &pos);
  
  friend class GameTest;
};

#endif