#include <string>
#include <sstream>
using namespace std;

#include <Card.h>

const int Card::JACK = 11;
const int Card::QUEEN = 12;
const int Card::KING = 13;
const int Card::ACE = 14;

// DO NOT CHANGE THIS
int Card::INSTANCE_COUNT = 0;
// DO NOT CHANGE THIS METHOD
int Card::getInstanceCount() {
  return INSTANCE_COUNT;
}

Card::Card(int rank, Suit suit) : rank(rank), suit(suit) {

  // LEAVE THIS LINE IN YOUR CONSTRUCTOR
  INSTANCE_COUNT++;
}

Card::~Card() {
}

int Card::getRank() {
  return rank;
}

Suit Card::getSuit() {
  return suit;
}

bool Card::isRed() {
  return suit == DIAMONDS || suit == HEARTS;
}

bool Card::isBlack() {
  return suit == CLUBS || suit == SPADES;
}

bool Card::higherThan(Card* other) {
  return this->rank > other->rank;
}

bool Card::lowerThan(Card* other) {
  return this->rank < other->rank;
}

bool Card::sameRankAs(Card* other) {
  return this->rank == other->rank;
}

bool Card::isFaceCard() {
  return rank >= JACK && rank <= KING;
}

bool Card::isAce() {
  return rank == ACE;
}

bool Card::equals(Card* other) {
  return rank == other->rank && suit == other->suit;
}

string Card::toString() {
  stringstream ss;
  if (rank < JACK) {
    ss << rank;
  } else if (rank == JACK) {
    ss << "Jack";
  } else if (rank == QUEEN) {
    ss << "Queen";
  } else if (rank == KING) {
    ss << "King";
  } else if (rank == ACE) {
    ss << "Ace";
  } else {
    ss << "INVALID";
  }
  ss << " of ";
  switch (suit) {
    case HEARTS:
      ss << "Hearts"; break;
    case DIAMONDS:
      ss << "Diamonds"; break;
    case CLUBS:
      ss << "Clubs"; break;
    case SPADES:
      ss << "Spades"; break;
  }

  return ss.str();
}

