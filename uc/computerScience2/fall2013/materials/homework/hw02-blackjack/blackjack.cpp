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


int main()
{
	// Seed the random number generator
	srand(time(NULL));
	// To get a random integer call, rand()
  // the value will be between 0 and RAND_MAX.
	
	card_t deck[DECK_SIZE];
	init_deck(deck);
}