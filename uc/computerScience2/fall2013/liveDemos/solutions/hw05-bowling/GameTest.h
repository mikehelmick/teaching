#ifndef GAME_TEST_H
#define GAME_TEST_H

#include <Game.h>
#include <GameRec.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class GameTest : public CxxTest::TestSuite {
protected:
  Game *game;
  
public:
  
  virtual void setUp() {
    game = new Game();
  }

  virtual void tearDown() {
    delete game;
  }
  
  virtual bool checkIntermediateScore() {
    return true;
  }
  
  void checkScore(int expected) {
    if (checkIntermediateScore() || game->isComplete()) {
      TS_ASSERT_EQUALS(expected, game->getCurrentScore());
    }
  }
  
  void testWeirdGame() {
    game->addRoll('X'); checkScore(0); TS_ASSERT(!game->isComplete());
    game->addRoll('5'); game->addRoll('4'); checkScore(28); TS_ASSERT(!game->isComplete());
    // Open frame, spare.
    game->addRoll('2'); game->addRoll('/'); checkScore(28); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(48); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('/'); checkScore(68); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('5'); checkScore(83); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(83); TS_ASSERT(!game->isComplete());
    game->addRoll('5'); game->addRoll('/'); checkScore(103); TS_ASSERT(!game->isComplete());
    game->addRoll('6'); game->addRoll('2'); checkScore(127); TS_ASSERT(!game->isComplete());
    // Tenth frame
    game->addRoll('X');
    game->addRoll('0');
    game->addRoll('1');
    checkScore(138); TS_ASSERT(game->isComplete());
  }
  
  void testGameCompleteCorrectly() {
    // Add 20 rolls
    for (int i = 1; i <= 20; i++) {
      game->addRoll('0');
      TS_ASSERT_EQUALS(i == 20, game->isComplete());
    }
  }

  void testGameCompleteStrikeInTenth() {
    // Add 9 frames
    for (int i = 1; i <= 18; i++) {
      game->addRoll('0');
      TS_ASSERT(!game->isComplete());
    }
    game->addRoll('X');
    TS_ASSERT(!game->isComplete());
    game->addRoll('X');
    TS_ASSERT(!game->isComplete());
    game->addRoll('X');
    TS_ASSERT(game->isComplete());
  }

  void testScoreAllOnes() {
    int score = 0;
    for (int i = 1; i <= 20; i++) {
      score++;
      game->addRoll('1');
      checkScore(score);
      TS_ASSERT_EQUALS(i == 20, game->isComplete());
    }
  }

  void testSpare() {
    game->addRoll('1');
    checkScore(1);
    TS_ASSERT(!game->isComplete());
    game->addRoll('1');
    checkScore(2);
    TS_ASSERT(!game->isComplete());
    game->addRoll('4');
    checkScore(6);
    TS_ASSERT(!game->isComplete());
    game->addRoll('/');
    checkScore(2);
    TS_ASSERT(!game->isComplete());
    game->addRoll('5');
    checkScore(22);
    TS_ASSERT(!game->isComplete());
  }

  void testStrikeAfterSpare() {
    game->addRoll('5');
    checkScore(5);
    TS_ASSERT(!game->isComplete());
    game->addRoll('/');
    checkScore(0);
    TS_ASSERT(!game->isComplete());
    game->addRoll('X');
    checkScore(20);
    TS_ASSERT(!game->isComplete());
    game->addRoll('X');
    checkScore(20);
    TS_ASSERT(!game->isComplete());
    game->addRoll('5');
    checkScore(45);
    TS_ASSERT(!game->isComplete());
    game->addRoll('2');
    checkScore(69);
    TS_ASSERT(!game->isComplete());
  }

  void testCaseFromAssignment() {
    // Frame 1
    game->addRoll('0');
    checkScore(0);
    TS_ASSERT(!game->isComplete());
    game->addRoll('1');
    checkScore(1);
    TS_ASSERT(!game->isComplete());
    // Frame 2
    game->addRoll('2');
    checkScore(3);
    TS_ASSERT(!game->isComplete());
    game->addRoll('4');
    checkScore(7);
    TS_ASSERT(!game->isComplete());
    // Frame 3
    game->addRoll('9');
    checkScore(16);
    TS_ASSERT(!game->isComplete());
    game->addRoll('0');
    checkScore(16);
    TS_ASSERT(!game->isComplete());
    // Frame 4
    game->addRoll('1');
    checkScore(17);
    TS_ASSERT(!game->isComplete());
    game->addRoll('8');
    checkScore(25);
    TS_ASSERT(!game->isComplete());
    // Frame 5
    game->addRoll('4');
    checkScore(29);
    TS_ASSERT(!game->isComplete());
    game->addRoll('/'); // Spare can't be calculated yet, so best known score is 29
    checkScore(25);
    TS_ASSERT(!game->isComplete());
    // Frame 6
    game->addRoll('5');
    checkScore(45);
    TS_ASSERT(!game->isComplete());
    game->addRoll('/'); // Spare can't be calculated yet, so best known score is 29
    checkScore(40);
    TS_ASSERT(!game->isComplete());
    // Frame 7
    game->addRoll('X'); // Stike can't yet be scored
    checkScore(60);
    TS_ASSERT(!game->isComplete());
    // Frame 8
    game->addRoll('X'); // Stike can't yet be scored
    checkScore(60);
    TS_ASSERT(!game->isComplete());
    // Frame 9
    game->addRoll('1'); 
    checkScore(81);
    TS_ASSERT(!game->isComplete());
    game->addRoll('0'); 
    checkScore(93);
    TS_ASSERT(!game->isComplete());
    // Frame 10
    game->addRoll('4'); 
    checkScore(97);
    TS_ASSERT(!game->isComplete());
    game->addRoll('/'); 
    checkScore(93);
    TS_ASSERT(!game->isComplete());
    game->addRoll('1'); 
    checkScore(104);
    TS_ASSERT(game->isComplete());
  }
  
  void testSpareStrikeInTenth() {
    game->addRoll('X');
    game->addRoll('5');
    game->addRoll('2');
    checkScore(24);
    game->addRoll('8');
    game->addRoll('/');
    game->addRoll('2');
    checkScore(38);
    game->addRoll('1');
    checkScore(39);
    game->addRoll('2');
    game->addRoll('4');
    checkScore(45);
    game->addRoll('7');
    game->addRoll('/');
    game->addRoll('2');
    checkScore(59);
    game->addRoll('1');
    checkScore(60);
    game->addRoll('8');
    game->addRoll('0');
    checkScore(68);
    game->addRoll('3');
    game->addRoll('0');
    checkScore(71);
    game->addRoll('X');
    game->addRoll('9');
    game->addRoll('/');
    TS_ASSERT(game->isComplete());
    checkScore(91);
  }
  
  void testStrikeInTenth() {
    game->addRoll('3');
    game->addRoll('4');
    checkScore(7);
    game->addRoll('1');
    game->addRoll('8');
    checkScore(16);
    game->addRoll('X');
    checkScore(16);
    game->addRoll('X');
    checkScore(16);
    game->addRoll('9');
    checkScore(45);
    game->addRoll('/');
    checkScore(65);
    game->addRoll('9');
    game->addRoll('/');
    game->addRoll('4');
    game->addRoll('0');
    checkScore(102);
    game->addRoll('7');
    game->addRoll('1');
    checkScore(110);
    game->addRoll('4');
    game->addRoll('/');
    game->addRoll('X');
    checkScore(130);
    game->addRoll('5');
    game->addRoll('1');
    TS_ASSERT(game->isComplete());
    checkScore(146);
  }
  
  void testLotsOSparesNormalTenth() {
    game->addRoll('3');
    game->addRoll('3');
    game->addRoll('9');
    game->addRoll('/');
    game->addRoll('6');
    game->addRoll('/');
    game->addRoll('2');
    game->addRoll('/');
    game->addRoll('2');
    game->addRoll('/');
    game->addRoll('8');
    game->addRoll('/');
    game->addRoll('1');
    game->addRoll('/');
    game->addRoll('7');
    game->addRoll('1');
    game->addRoll('X');
    game->addRoll('7');
    game->addRoll('1');
    TS_ASSERT(game->isComplete());
    checkScore(126);
  }

  void testGutterAndThenOne() {
    game->addRoll('0'); game->addRoll('1'); checkScore(1); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(2); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(3); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(4); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(5); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(6); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(7); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(8); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(9); TS_ASSERT(!game->isComplete());
    game->addRoll('0'); game->addRoll('1'); checkScore(10); TS_ASSERT(game->isComplete());
  }

  void testPerfectGame() {
    game->addRoll('X'); checkScore(0); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(0); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(30); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(60); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(90); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(120); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(150); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(180); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(210); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(240); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(270); TS_ASSERT(!game->isComplete());
    game->addRoll('X'); checkScore(300);
    TS_ASSERT(game->isComplete()); 
    TS_ASSERT_EQUALS(120, game->getPinsKnockedDown());
  }
};

#endif