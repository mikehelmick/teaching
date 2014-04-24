#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include <Card.h>
#include <Deck.h>

int main(int argc, char* argv[]) {
  // Seed the random number generatorA
  if (argc == 1) {
    srand(time(NULL));
  } else {
    srand(atoi(argv[1]));
  }

  Deck* deck = new Deck();

  cout << "Printing cards in order: " << endl;
  while (deck->cardsInDeck() > 0) {
    Card* card = deck->drawCard();
    cout << card->toString() << endl;
  }

  deck->returnAllToDeck();

  deck->shuffle();

  cout << "Shuffled cards: " << endl;
  while (deck->cardsInDeck() > 0) {
    Card* card = deck->drawCard();
    cout << card->toString() << endl;
  }

  delete deck;
  deck = NULL;
}
