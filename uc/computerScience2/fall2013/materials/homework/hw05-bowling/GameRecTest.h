#ifndef GAME_REC_TEST_H
#define GAME_REC_TEST_H

#include <Game.h>
#include <GameRec.h>
#include <GameTest.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class GameRecTest : public GameTest {
public:
  
  virtual void setUp() {
    game = new GameRec();
  }

  virtual void tearDown() {
    delete game;
  }
  
  virtual bool checkIntermediateScore() {
    return false;
  }
  
};

#endif