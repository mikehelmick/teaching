#ifndef DECK_TEST_H
#define DECK_TEST_H

#include <Deck.h>
#include <Card.h>

#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cxxtest/TestSuite.h>

using namespace std;

class DeckTest : public CxxTest::TestSuite {
public:
  vector<string> getSuitNames() {
    vector<string> sn;
    sn.push_back("Hearts");
    sn.push_back("Diamonds");
    sn.push_back("Spades");
    sn.push_back("Clubs");
    return sn;
  }

  vector<string> getRankNames() {
    vector<string> rn;
    rn.push_back("0"); // invalid, conveience
    rn.push_back("1"); // same
    rn.push_back("2");
    rn.push_back("3");
    rn.push_back("4");
    rn.push_back("5");
    rn.push_back("6");
    rn.push_back("7");
    rn.push_back("8");
    rn.push_back("9");
    rn.push_back("10");
    rn.push_back("Jack");
    rn.push_back("Queen");
    rn.push_back("King");
    rn.push_back("Ace");
    return rn;
  }

  vector<string> loadShuffleFile(string fname) {
    ifstream inFile;
    inFile.open(fname.c_str());

    vector<string> names;
    for (int i = 0; i < 52; i++) {
      string name;
      getline(inFile, name);
      names.push_back(name);
    }

    inFile.close(); 
    return names;
  }

  void testDeckConstructor() {
    vector<string> suitNames = getSuitNames();
    vector<string> rankNames = getRankNames();

    Deck deck;
    TS_ASSERT_EQUALS(52, deck.cardsInDeck());
    TS_ASSERT_EQUALS(0, deck.cardsOutOfDeck()); 
    // Draw all the cards out of the deck, assert the order.
    // The deck hasn't been shuffled, so they should come out in
    // reverse initialization order.
    int suit = CLUBS;
    int rank = Card::ACE;
    while (deck.cardsInDeck() > 0) {
      Card* card = deck.drawCard();
      // Check card
      TS_ASSERT_EQUALS(suit, card->getSuit());
      TS_ASSERT_EQUALS(rank, card->getRank());
      string name = rankNames[card->getRank()] + " of " + suitNames[card->getSuit()];
      TS_ASSERT_EQUALS(name, card->toString());

      rank--;
      if (rank < 2) {
        rank = Card::ACE;
        suit--;
      }
    }
    // This assumes tests run in order, exactly 52 cards should have been created
    TS_ASSERT_EQUALS(52, Card::getInstanceCount());
  }

  void testOneShuffle() {
    vector<string> expected = loadShuffleFile("shuffle1.txt");

    srand(10);
    Deck deck;
    deck.shuffle();
    // If the shuffle algorithm is implemented correctly, the card will come out
    // in a consistent order. 
    TS_ASSERT_EQUALS(52, deck.cardsInDeck());
    for (int i = 0; i < 52; i++) { 
      Card* card = deck.drawCard();
      TS_ASSERT_EQUALS(expected[i], card->toString());
    }
  }

  void testTwoShuffle() {
    vector<string> expected2 = loadShuffleFile("shuffle2.txt");

    srand(100);
    Deck deck;
    deck.shuffle();
    deck.shuffle();
    TS_ASSERT_EQUALS(52, deck.cardsInDeck());
    for (int i = 0; i < 52; i++) {
      Card* card = deck.drawCard();
      TS_ASSERT_EQUALS(expected2[i], card->toString());
    }  
  }

};

#endif
