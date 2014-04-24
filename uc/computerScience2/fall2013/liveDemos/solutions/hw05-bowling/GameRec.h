#ifndef GAME_REC_H
#define GAME_REC_H

#include <Game.h>

#include <iostream>
#include <vector>
using namespace std;

class GameRec : public Game {
public:
  /** Default constructor. Initializes an empty game.
    */
  GameRec();

  /** Destructor */
  virtual ~GameRec();

  /** Returns the current score, based on what can be calculated.
   * If the trailing spare or strike can't be completly calculated yet, 
   * it isn't included
   */
  virtual int getCurrentScore();

private:
  int score(vector<char> &rolls, int startingAt, int frame);
  static bool isSpare(char ch);
  static bool isStrike(char ch);
  static int pinValue(char ch);  
};

#endif