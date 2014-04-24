#ifndef DECK_H
#define DECK_H

#include <vector>
using namespace std;

#include <Card.h>

class Deck {
public:
  Deck();

  virtual ~Deck();

  void shuffle();

  int cardsInDeck();

  int cardsOutOfDeck();

  Card* drawCard();

  void returnAllToDeck();

private:
  vector<Card*> cards;
  vector<Card*> outOfDeck;

};

#endif
