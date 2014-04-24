#ifndef HANGMAN_TEST_H
#define HANGMAN_TEST_H

#include <Hangman.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class HangmanTest : public CxxTest::TestSuite {
public:
  void testConstructor() {
    Hangman hm("abdicated");
    TS_ASSERT_EQUALS(6, hm.getMissesRemaining());
    TS_ASSERT_EQUALS("_________", hm.getCurrentDisplay());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());
  }

  void testMiss() {
    Hangman hm("abdicated");
    TS_ASSERT_EQUALS(6, hm.getMissesRemaining());
    TS_ASSERT_EQUALS("_________", hm.getCurrentDisplay());
    hm.guessLetter('z');
    TS_ASSERT_EQUALS(5, hm.getMissesRemaining());
    TS_ASSERT_EQUALS("z", hm.getIncorrectGuesses());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());
  }

  void testHit() {
    Hangman hm("abdicated");
    TS_ASSERT_EQUALS(6, hm.getMissesRemaining());
    TS_ASSERT_EQUALS("_________", hm.getCurrentDisplay());

    hm.guessLetter('b');
    TS_ASSERT_EQUALS(6, hm.getMissesRemaining());
    TS_ASSERT_EQUALS("_b_______", hm.getCurrentDisplay());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());
  }

  void testLosingGame() {
    Hangman hm("detergent", 3);
    TS_ASSERT_EQUALS(3, hm.getMissesRemaining());
    TS_ASSERT(!hm.isGameOver());
    hm.guessLetter('a');
    TS_ASSERT_EQUALS(2, hm.getMissesRemaining());
    TS_ASSERT(!hm.isGameOver());
    hm.guessLetter('i');
    TS_ASSERT_EQUALS(1, hm.getMissesRemaining());
    TS_ASSERT(!hm.isGameOver());
    hm.guessLetter('o');
    TS_ASSERT_EQUALS(0, hm.getMissesRemaining());
    TS_ASSERT(hm.isGameOver());
    TS_ASSERT(!hm.isWinner());
  }

  void testWinningGame() {
    Hangman hm("detergent");

    hm.guessLetter('e');
    TS_ASSERT_EQUALS("_e_e__e__", hm.getCurrentDisplay());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());

    hm.guessLetter('d');
    TS_ASSERT_EQUALS("de_e__e__", hm.getCurrentDisplay());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());

    hm.guessLetter('t');
    TS_ASSERT_EQUALS("dete__e_t", hm.getCurrentDisplay());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());

    hm.guessLetter('r');
    TS_ASSERT_EQUALS("deter_e_t", hm.getCurrentDisplay());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());

    hm.guessLetter('g');
    TS_ASSERT_EQUALS("deterge_t", hm.getCurrentDisplay());
    TS_ASSERT(!hm.isWinner());
    TS_ASSERT(!hm.isGameOver());

    hm.guessLetter('n');
    TS_ASSERT_EQUALS("detergent", hm.getCurrentDisplay());
    TS_ASSERT(hm.isWinner());
    TS_ASSERT(hm.isGameOver());
  }
};

#endif
