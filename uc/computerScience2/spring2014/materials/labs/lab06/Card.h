#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

enum Suit {
  HEARTS,
  DIAMONDS,
  SPADES,
  CLUBS
};

class Card {
public:
  Card(int rank, Suit suit);

  virtual ~Card();

  int getRank();

  Suit getSuit();

  bool isRed();

  bool isBlack();

  bool higherThan(Card* other);

  bool lowerThan(Card* other);

  bool sameRankAs(Card* other);

  bool isFaceCard();

  bool isAce();

  string toString();

  bool equals(Card* other);

  static const int JACK;
  static const int QUEEN;
  static const int KING;
  static const int ACE;

  // DO NOT CHANGE THIS LINE
  static int getInstanceCount();

private:
  int rank;
  Suit suit;

  // DO NOT CHANGE THIS LINE
  static int INSTANCE_COUNT;
};

#endif
