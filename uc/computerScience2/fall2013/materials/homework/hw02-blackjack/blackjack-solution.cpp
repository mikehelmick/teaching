// CS1022 - Homework 2, Blackjack
// Author: Mike Helmick, mike.helmick@uc.edu

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

enum winner_t {
	NONE,
	PLAYER,
	PLAYER_BLACKJACK,
	DEALER,
	DEALER_BLACKJACK,
	PUSH
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

/**
 * Selects a card from the deck. 
 * Marks that card has being dealtdealt
 */
int select_card(card_t deck[]) {
	int card = -1;
	while (card < 0 || deck[card].dealt == true)
	{
		card = rand() % 52;
	}
	deck[card].dealt = true;
	return card;
}

/**
 * prints the rank of suit for a single card
 */
void print_card(int card, const card_t deck[]) {
  if (deck[card].rank >= 2 && deck[card].rank <= 10) {
		cout << deck[card].rank;
	} else if (deck[card].rank == 1) {
		cout << "Ace";
	} else if (deck[card].rank == 11) {
		cout << "Jack"; 
  } else if (deck[card].rank == 12) {
		cout << "Queen";
  } else if (deck[card].rank == 13) {
		cout << "King";
  }

	cout << " of ";
  if (deck[card].suit == HEARTS) {
		cout << "hearts";
  } else if (deck[card].suit == DIAMONDS) {
		cout << "diamonds";
  } else if (deck[card].suit == SPADES) {
		cout << "spades";
  } else if (deck[card].suit == CLUBS) {
		cout << "clubs";
  }
}

int hand_value(const vector<int> &hand, const card_t deck[]) {
	int low_value = 0;
	int high_value = 0;
	bool contains_ace = false;

	for (int i = 0; i < hand.size(); i++) {
		const int rank = deck[hand[i]].rank;
		if (rank == 1) {
			low_value++;
			if (contains_ace) {
				high_value++;
			} else {
			  high_value += 11;
      }
			contains_ace = true;
		} else if (rank >= 2 && rank <= 10) {
			low_value += rank;
		  high_value += rank;
		}	else {
			// rank > 10
			low_value += 10;
			high_value += 10;
		}	
	}
	if (high_value == 21 || low_value == 21) {
		return 21;
	}
	if (high_value <= 21) {
		return high_value;
	}
	return low_value;
}

void print_hand(const string &player, const vector<int> &hand, const card_t deck[], const bool full_hand) {
	cout << "Hand for " << player << endl;
	int limit = 1;
	if (full_hand) {
		limit = hand.size();
	}
	for (int i = 0; i < limit; i++) {
		print_card(hand[i], deck);
		cout << endl;
	}
	if (full_hand) {
  	cout << " total: " << hand_value(hand, deck) << endl;
  }
	cout << endl;
}

void deal(vector<int> &hand, card_t deck[]) {
	hand.push_back(select_card(deck));
}

winner_t winner(const bool player_stands, const vector<int> &player, const vector<int> &dealer, const card_t deck[]) {
	const int player_val = hand_value(player, deck);
	const int dealer_val = hand_value(dealer, deck);
	
	// blackjack conditions.
	if (player_val == 21 && player.size() == 2) {
		if (dealer_val == 21) {
			// Double blackjack
			return PUSH;
		} else {
			return PLAYER_BLACKJACK;
		}
	}
	if (dealer_val == 21 && dealer.size() == 2) {
		return DEALER_BLACKJACK;
	}

  // Dealer wins
  if (dealer_val == 21 && player_val != 21) {
		return DEALER;
  }
  // Push
  if (dealer_val == 21 && player_val == 21) {
		return PUSH;
  }
  if (dealer_val >= 17 && dealer_val == player_val && player_stands) {
		return PUSH;
  }
  // Player busts
  if (player_val > 21) {
		return DEALER;
  }
  // Dealer busts
  if (dealer_val > 21) {
		return PLAYER;
  }
  // Dealer wins
  if (player_stands && dealer_val >= 17 && dealer_val > player_val) {
		return DEALER;
  }
  if (player_stands && dealer_val >= 17 && dealer_val < player_val) {
		return PLAYER;
  }

	return NONE;
}

int main()
{
	// Seed the random number generator
	srand(time(NULL));
	
	card_t deck[DECK_SIZE];
	init_deck(deck);

	const string PLAYER_NAME("player");
	const string DEALER_NAME("dealer");
	vector<int> player_cards;
	vector<int> dealer_cards;

  // Deal two cards to each player
	deal(player_cards, deck);
	deal(player_cards, deck);
	deal(dealer_cards, deck);
	deal(dealer_cards, deck);
	print_hand(DEALER_NAME, dealer_cards, deck, false);
	print_hand(PLAYER_NAME, player_cards, deck, true);

	string answer("");

	bool player_stands = false;
  while(winner(player_stands, player_cards, dealer_cards, deck) == NONE) {
	  if (!player_stands) {
			cout << "(H)it or (S)tay? " << endl;
			getline(cin, answer);
			while (!(answer == "H" || answer == "S")) {
				cout << "Please enter 'H' for Hit or 'S' for Stay: " << endl;
				getline(cin, answer);
			}
			if (answer == "H") {
				cout << "You have choen hit, dealing another card." << endl;
				deal(player_cards, deck);
				if (hand_value(player_cards, deck) > 21) {
					cout << "BUST!" << endl;
				}
			} else {
				cout << "You have chosen to stay, here is your final hand." << endl;
				player_stands = true;
			}
			print_hand(PLAYER_NAME, player_cards, deck, true);
	  }
	
	  if (player_stands) {
		  // resolve dealer hand
			print_hand(DEALER_NAME, dealer_cards, deck, true);
			if (hand_value(dealer_cards, deck) < 17) {
				cout << "Dealer must hit." << endl;
				deal(dealer_cards, deck);
				if (hand_value(player_cards, deck) > 21) {
					cout << "Dealer busts!" << endl;
				}
				print_hand(DEALER_NAME, dealer_cards, deck, true);
			} else {
				cout << "dealer must stay." << endl;
			}
	  }
  }

  // print winner
	winner_t the_winner = winner(player_stands, player_cards, dealer_cards, deck);
  if (the_winner == DEALER_BLACKJACK) {
		cout << "BLACKJACK - Dealer wins with blackjack." << endl;
  } else if (the_winner == PLAYER_BLACKJACK) {
		cout << "BLACKJACK! You win!" << endl;
  } else if (the_winner == PLAYER) {
		cout << "You win!" << endl;
  } else if (the_winner == DEALER) {
		cout << "Dealer wins." << endl;
  } else {
		cout << "Push." << endl;
  }

	cout << "Final Hands" << endl;
	print_hand(DEALER_NAME, dealer_cards, deck, true);
	print_hand(PLAYER_NAME, player_cards, deck, true);
}