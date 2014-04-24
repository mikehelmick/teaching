#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <Player.h>

#include <cxxtest/TestSuite.h>

class PlayerTest : public CxxTest::TestSuite {
public:

  void testMove() {
    Player p;
    TS_ASSERT_EQUALS(0, p.getSpace());
    p.setSpace(3);
    TS_ASSERT_EQUALS(3, p.getSpace());
    TS_ASSERT(!p.isInJail());
  }

  void testMoveInOutOfJail() {
    Player p;
    p.moveToJail(10);
    TS_ASSERT(p.isInJail());
    p.setSpace(11);
    TS_ASSERT(!p.isInJail());
  }

  void testJailCards() {
    Player p;
    TS_ASSERT(!p.hasGetOutOfJail());
    p.awardComChestOutOfJail();
    TS_ASSERT(p.hasGetOutOfJail());
    TS_ASSERT(p.hasComChestOutOfJail());
    p.useOutOfJailCard();
    TS_ASSERT(!p.hasGetOutOfJail());
  }

  void testMultipleJailCards() {
    Player p;
    TS_ASSERT(!p.hasGetOutOfJail());
    p.awardComChestOutOfJail();
    p.awardChanceOutOfJail();
    TS_ASSERT(p.hasGetOutOfJail());
    TS_ASSERT(p.hasChanceGetOutOfJail());
    TS_ASSERT(p.hasComChestOutOfJail());
    p.useOutOfJailCard();
    TS_ASSERT(p.hasGetOutOfJail()); 
    TS_ASSERT(!p.hasChanceGetOutOfJail());
    TS_ASSERT(p.hasComChestOutOfJail());
    p.useOutOfJailCard();
    TS_ASSERT(!p.hasGetOutOfJail()); 
    TS_ASSERT(!p.hasChanceGetOutOfJail());
    TS_ASSERT(!p.hasComChestOutOfJail());
  }
};

#endif
