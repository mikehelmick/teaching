#ifndef IN_BETWEEN_H
#define IN_BETWEEN_H

#include <Deck.h>

class InBetween {
public:
  InBetween();

  virtual ~InBetween();

  void play();

  long getBalance();

private:
  Deck* deck;
  long account;
  long games;
  long wins;

  long getWager();
  void maybeShuffle();
};

#endif

