#ifndef CARD_TEST_H
#define CARD_TEST_H

#include <Card.h>

#include <cxxtest/TestSuite.h>

class CardTest : public CxxTest::TestSuite {
public:

  void testBoringCard() {
    Card c("Bank error in your favor", "Community Chest");
    TS_ASSERT_EQUALS("Bank error in your favor", c.getName());
    TS_ASSERT_EQUALS("Community Chest", c.getType());
    TS_ASSERT(!c.isGoToJail());
    TS_ASSERT(!c.isOutOfJailFree());
    TS_ASSERT(!c.isAdvanceToCard());
  }

  void testAdvanceCard() {
    Card c("Advance to Go", "Community Chest", 0);
    TS_ASSERT_EQUALS("Advance to Go", c.getName());
    TS_ASSERT_EQUALS("Community Chest", c.getType());
    TS_ASSERT(!c.isGoToJail());
    TS_ASSERT(!c.isOutOfJailFree());
    TS_ASSERT(c.isAdvanceToCard());
    TS_ASSERT_EQUALS(0, c.getAdvanceToSpace()[0]);
  }
  
  void testGoToJailCard() {
    Card c("Go to Jail", "Chance", 10, true);
    TS_ASSERT_EQUALS("Go to Jail", c.getName());
    TS_ASSERT_EQUALS("Chance", c.getType());
    TS_ASSERT(c.isGoToJail());
    TS_ASSERT(!c.isOutOfJailFree());
    TS_ASSERT(c.isAdvanceToCard());
    TS_ASSERT_EQUALS(10, c.getAdvanceToSpace()[0]);
  }

  void testAdvanceToRailroad() {
    int spaces[] = {15, 5, 35, 25};
    Card c("Advance to Nearest Railroad", "Chance", spaces, 4);
    TS_ASSERT_EQUALS("Advance to Nearest Railroad", c.getName());
    TS_ASSERT_EQUALS("Chance", c.getType());
    TS_ASSERT(!c.isGoToJail());
    TS_ASSERT(!c.isOutOfJailFree());
    TS_ASSERT(c.isAdvanceToCard());
    TS_ASSERT_EQUALS(5, c.getAdvanceToSpace()[0]);
    TS_ASSERT_EQUALS(15, c.getAdvanceToSpace()[1]);
    TS_ASSERT_EQUALS(25, c.getAdvanceToSpace()[2]);
    TS_ASSERT_EQUALS(35, c.getAdvanceToSpace()[3]);
    TS_ASSERT_EQUALS(4, c.getNumAdvanceToSpaces());
  }
};

#endif
