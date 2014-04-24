#include <Deck.h>
#include <Card.h>
#include <cstdlib>
#include <iostream>
using namespace std;

Deck::Deck() {
  // initalize the deck
  // Suit in outer loop: hearts, diamons, spades, clubs
  // Then rank, 2 through Ace
  for (int suit = HEARTS; suit <= CLUBS; suit++) {
    for (int rank = 2; rank <= Card::ACE; rank++) {
      cards.push_back(new Card(rank, (Suit) suit));
    }
  }
}

Deck::~Deck() {
  returnAllToDeck();
  while (!cards.empty()) {
    delete cards[cards.size() - 1];
    cards.pop_back();
  }
}

void Deck::shuffle() {
  // 7 pass shuffle
  returnAllToDeck();
  for (int pass = 0; pass < 7; pass++) {
    for (unsigned int i = 0; i < cards.size(); i++) {
      unsigned int j = rand() % cards.size();
      while (j == i) {
        j = rand() % cards.size();
      }
      // Swap these elements
      Card* tmp = cards[i];
      cards[i] = cards[j];
      cards[j] = tmp;
    }
  }
}

int Deck::cardsInDeck() {
  return cards.size();
}

int Deck::cardsOutOfDeck() {
  return outOfDeck.size();
}

Card* Deck::drawCard() {
  Card* drawn = cards[cards.size() - 1];
  cards.pop_back();
  outOfDeck.push_back(drawn);
  return drawn;
}

void Deck::returnAllToDeck() {
  for (unsigned int i = 0; i < outOfDeck.size(); i++) {
    cards.push_back(outOfDeck[i]);
  }
  outOfDeck.clear();
}

