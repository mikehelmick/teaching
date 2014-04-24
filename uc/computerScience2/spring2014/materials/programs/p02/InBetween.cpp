#include <Card.h>
#include <Deck.h>
#include <InBetween.h>
#include <iostream>
using namespace std;

InBetween::InBetween() 
    : deck(new Deck()), account(100),
      games(0), wins(0) {
  deck->shuffle();
}

InBetween::~InBetween() {
  delete deck;
}

void InBetween::play() {

  while (account > 1) {
    maybeShuffle();
    cout << endl;

    Card* card1 = deck->drawCard();
    cout << "Card 1: " << card1->toString() << endl;
    Card* card2 = deck->drawCard();
    cout << "Card 2: " << card2->toString() << endl;

    if (card1->sameRankAs(card2)) {
      cout << "Match, no bet." << endl;
      continue; 
    }
    long wager = getWager();
    if (wager == 0) {
      cout << " ** pass **" << endl;
      continue;
    }

    Card* card3 = deck->drawCard();
    cout << " ** " << card3->toString() << " **" << endl;

    if ((card3->higherThan(card1) && card3->lowerThan(card2))
        || (card3->higherThan(card2) && card3->lowerThan(card1))) {
      cout << "You win $" << wager << endl;
      account += wager;
    } else if (card3->sameRankAs(card1) || card3->sameRankAs(card2)) {
      cout << "Match! You pay double" << endl;
      wager *= 2;
      cout << "You pay $" << wager << endl;
      account -= wager;
    } else {
      // regular loss
      cout << "You loose, pay $" << wager << endl;
      account -= wager;
    }
  }
  if (account == 1) {
    cout << "Sorry, you have to have more than $1 to play." << endl;
  } else {
    cout << "Sorry, you ran out of money." << endl;
  }
}

void InBetween::maybeShuffle() {
  if (deck->cardsInDeck() < 3) {
    cout << "Less than 3 cards remain, shuffling." << endl;
    deck->shuffle();
  } 
}

long InBetween::getWager() {
  long maxBet = account / 2;
  cout << "Account balance $" << getBalance() << ". Bet between 1 and " << maxBet << endl
      << "What is your wager (0 to pass)? ";
  long wager;
  cin >> wager;
  while (wager < 0 || wager > maxBet) {
    cout << "Your wager must be between 0 (pass) and " << maxBet << endl;
    cout << "What is your wager? ";
    cin >> wager;
  }
  return wager;
}

long InBetween::getBalance() {
  return account;
}

