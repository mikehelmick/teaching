// CS1022 - Homework 2, Blackjack
// Plays a single hand of blackjack with one player against the dealer.
// Author: your name, your@email

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

enum suit_t {
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS
};

struct card_t {
	suit_t suit;
	int rank;
	bool dealt;
};

const int DECK_SIZE = 52;

/**
 * Initialize the deck so that all cards exist, and are not yet dealt.
 */
void init_deck(card_t deck[]) {
	int pos = 0;
	for (int s = 0; s < 4; s++) {
		for (int rank = 1; rank <= 13; rank++) {
			deck[pos].suit = (suit_t) s;
			deck[pos].rank = rank;
			deck[pos].dealt = false;
			pos++;
		}
	}
}

void printHand(vector<int> &hand, card_t deck[]){
  for(int i = 0; i < hand.size(); i++){
    int deck_index = hand[i];
    cout << "index: " <<i << " value: " <<  hand[i];
    cout << " rank: " << deck[deck_index].rank << endl;
  }
}

int getRandomCard(card_t deck[]){
  int ret = rand() % DECK_SIZE;
  while(deck[ret].dealt){
    ret = rand() % DECK_SIZE;
  }
  // ret must be an index that has not been dealt
  deck[ret].dealt = true;
  return ret;
}

int main()
{
	// Seed the random number generator
	srand(time(NULL));
	// To get a random integer call, rand()
  // the value will be between 0 and RAND_MAX.
	
	card_t deck[DECK_SIZE];
	//fl a[10];
	//cout << time(NULL) << endl;
	//return 0;
	init_deck(deck);
	vector<int> dealer;
	
	// put 2 cards in dealers hand
	int c = getRandomCard(deck);
	dealer.push_back(c);
	// get second card
	dealer.push_back(getRandomCard(deck));

	printHand(dealer, deck);
}
