// CS1022 - Homework 2, Blackjack
// Plays a single hand of blackjack with one player against the dealer.
// Author: Paul Talaga paul.talaga@uc.edu

// Solution 1 - No vectors!  We store card location in card struct.

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// Represent all possible suits
enum suit_t {
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS
};

// Represent card locations
enum location_t {
  DECK,
  DEALER,
  PLAYER1
};

// How should the first Ace be treated?
enum score_t {
  LOW,
  HIGH
};

// Card struct storing the suit, rank, and location of card.
struct card_t {
	suit_t suit;
	int rank;
	location_t location;
};

const int DECK_SIZE = 52;

/**
 * Initialize the deck so that all cards exist, and are in DECK.
 */
void init_deck(card_t deck[]) {
	int pos = 0;
	for (int s = 0; s < 4; s++) {
		for (int rank = 1; rank <= 13; rank++) {
			deck[pos].suit = (suit_t) s;
			deck[pos].rank = rank;
			deck[pos].location = DECK;
			pos++;
		}
	}
}

/**
  * Print the first num_cards owned by player p in the given deck.
  * If num_cards < 0, prints all
  */
void printPlayer(card_t deck[],location_t p, int num_cards){
  if(p == DECK){
    cout << "The deck contains:\n";
  }else if(p == DEALER){
    cout << "The dealer has:\n";
  }else if(p == PLAYER1){
    cout << "Player 1 has:\n";
  }else{
    cerr << "Unknown player!" << endl;
  }
  for(int i = 0; i < DECK_SIZE; i++){
    if( deck[i].location == p && num_cards != 0 ){
      if(deck[i].rank == 1){
        cout << "    Ace of ";
      }else if(deck[i].rank == 11){
        cout << "   Jack of ";
      }else if(deck[i].rank == 12){
        cout << "  Queen of ";
      }else if(deck[i].rank == 13){
        cout << "   King of ";
      }else{
        cout << "      " << deck[i].rank << " of ";
      }
      if(deck[i].suit == HEARTS){
        cout << "Hearts\n";
      }else if(deck[i].suit == SPADES){
        cout << "Spades\n";
      }else if(deck[i].suit == DIAMONDS){
        cout << "Diamonds\n";
      }else if(deck[i].suit == CLUBS){
        cout << "Clubs\n";
      }else{
        cerr << "Unknown suit: " << deck[i].suit << endl;
      }
      num_cards--;
    }
  }
  cout << endl;
}

/**
  * Returns the index of a random card in the DECK.
  */
int getCard(card_t deck[]){
  int i = rand() % DECK_SIZE;
  int max_tries = 9999; // prevents endless looking
  while(deck[i].location != DECK){
    i = rand() % DECK_SIZE;
    if(max_tries < 0){
      cerr << "No cards left";
      return -1;
    }
    max_tries--;
  }
  return i;
}

/**
  * Returns the points for that player
  * If ace is HIGH, then count the first as as 11, otherwise if
  * LOW, count as 1.
  */
int getPoints(card_t deck[], location_t player, score_t ace){
  int points = 0;
  bool found_ace = false;             // Will only count the first ace 
  for(int i = 0; i < DECK_SIZE; i++){
    if(deck[i].location == player){
      if(deck[i].rank >= 11){
        points += 10;
      }else if(deck[i].rank == 1 && ace == HIGH && !found_ace){
        found_ace = true;
        points += 11;
      }else{
        points += deck[i].rank;
      }
    }
  }
  return points;
}

int main()
{
	// Seed the random number generator
	srand(time(NULL));

  // Declare and initialize the deck	
	card_t deck[DECK_SIZE];
	init_deck(deck);
	
	// Deal 2 cards to dealer
	int card = getCard(deck);
	deck[card].location = DEALER; // Set the location
	card = getCard(deck);
	deck[card].location = DEALER;
	
	// Print one of the dealer's cards
	printPlayer(deck, DEALER,1);
	cout << " Other card hidden\n";
	
	// Deal 2 cards to player1
	card = getCard(deck);
	deck[card].location = PLAYER1;
	card = getCard(deck);
	deck[card].location = PLAYER1;
	
	// Loop until player wants to fold
	int player1score = getPoints(deck, PLAYER1, LOW);
	bool fold = false;
	string input;
	while(fold == false){
	  // Print the player1's hand
	  printPlayer(deck, PLAYER1,-1);
	  player1score = getPoints(deck, PLAYER1, LOW);
	  cout << "You have " << player1score << " points." << endl;
	  // Handle if an ace is present, print high score
	  if(getPoints(deck, PLAYER1, HIGH) != player1score){
	    cout << " (Or " << getPoints(deck, PLAYER1, HIGH) << " if ace is high.)\n";
	  };
	  cout << "(H)it or (F)old?\n";
	  cin >> input;
	  if(input == "H"){
	    // If (H)it, get new card
	    card = getCard(deck);
	    deck[card].location = PLAYER1;
	  }else if(input == "F"){
	    // If (F)old, trigger to get out
	    fold = true;
	  } // else loop and show hand again with no change
	}
	// Fill up dealer's hand until >= 17  use soft ace
	while(getPoints(deck, DEALER, LOW) < 17){
	  card = getCard(deck);
	  deck[card].location = DEALER;
	}
	
	// Print all hands
	cout << "*******************************\n";
	printPlayer(deck, DEALER,-1);
	cout << endl;
	printPlayer(deck, PLAYER1,-1);
	cout << "*******************************\n";
	// Compute best score for player1
	if(getPoints(deck, PLAYER1, LOW) < getPoints(deck, PLAYER1, HIGH)
	    && getPoints(deck, PLAYER1, HIGH) < 21){
	  player1score = getPoints(deck, PLAYER1, HIGH);
	}
	
	int dealerscore = getPoints(deck, DEALER, LOW); 
	
	// Print scores
	cout << "Dealer: " << dealerscore << endl;
	cout << "   You: " << player1score << endl << endl;
	
	// Compute winner and print text.
	if(player1score > 21){
	  cout << "You BUST!  Dealer wins.  :-(\n";
	}else if(dealerscore > 21){
	  cout << "Dealer BUSTS!  You win!  :-)\n";
	}else if(player1score > dealerscore){
	  cout << "You were closer to 21 than dealer.  You win! :-)\n";
	}else if(dealerscore > player1score){
	  cout << "Dealer was closer to 21 than you.  Dealer wins.  :-(\n";
	}else if(dealerscore == player1score){
	  cout << "You match dealer's score.  A push.  :-/\n";
	}else{
	  cerr << "You missed a case!\n";
	}
	cout << endl;
}