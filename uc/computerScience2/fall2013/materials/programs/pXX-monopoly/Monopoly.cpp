#include <Player.h>
#include <Monopoly.h>
#include <LinkedList.h>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

const int Monopoly::GO_TO_JAIL = 30;
const int Monopoly::JAIL = 10;
const int Monopoly::NUM_SPACES = 40;

// Creates a new monopoply simulation.
Monopoly::Monopoly(int players, int turns) : IMonopoly(players, turns) {
  // Create players
  for (int i = 0; i < players; i++) {
    this->players.push_back(new Player());
  }
  
  // Create board
  // 0 - Go->Connecticut
  board.push_back("Go");
  board.push_back("Mediterranean Avenue");
  board.push_back("Community Chest");
  board.push_back("Baltic Avenue");
  board.push_back("Income Tax");
  board.push_back("Reading Railroad");
  board.push_back("Oriental Avenue");
  board.push_back("Chance");
  board.push_back("Vermont Avenue");
  board.push_back("Connecticut Avenue");
  // 10 - Jail->NY
  board.push_back("In Jail/Just Visiting");
  board.push_back("St. Charles Place");
  board.push_back("Electric Company");
  board.push_back("States Avenue");
  board.push_back("Virginia Avenue");
  board.push_back("Pennsylvania Railroad");
  board.push_back("St. James Place");
  board.push_back("Community Chest");
  board.push_back("Tennessee Avenue");
  board.push_back("New York Avenue");
  // 20 -> Free Parking - Marvin Gardens
  board.push_back("Free Parking");
  board.push_back("Kentucky Avenue");
  board.push_back("Chance");
  board.push_back("Indiana Avenue");
  board.push_back("Illinois Avenue");
  board.push_back("B. & O. Railroad");
  board.push_back("Alantic Avenue");
  board.push_back("Ventnor Avenue");
  board.push_back("Water Works");
  board.push_back("Marvin Gardens");
  // 30 - Go To Jail -> Boardwalk
  board.push_back("Go To Jail");
  board.push_back("Pacific Avenue");
  board.push_back("North Carolina AVenue");
  board.push_back("Community Chest");
  board.push_back("Pennsylvania Avenue");
  board.push_back("Short Line");
  board.push_back("Chance");
  board.push_back("Park Place");
  board.push_back("Luxury Tax");
  board.push_back("Boardwalk");
  
  comChestSpaces.insert(2);
  comChestSpaces.insert(17);
  comChestSpaces.insert(33);
  chanceSpaces.insert(7);
  chanceSpaces.insert(22);
  chanceSpaces.insert(36);
  
  // Create decks
  //chanceCards
  chanceCards.offer(new Card("Advance to Go", "Chance", 0));
  chanceCards.offer(new Card("Advance to Illinois Ave.", "Chance", 24));
  chanceCards.offer(new Card("Advance to St. Charles Place", "Chance", 11));
  {
    int spaces[] = {12, 28};
    chanceCards.offer(new Card("Advance token to nearest Utility", "Chance", spaces, 2));
  }
  {
    int spaces[] = {5, 15, 25, 35};
    chanceCards.offer(new Card("Advance to nearest Railroad", "Chance", spaces, 4));
  }
  chanceCards.offer(new Card("Bank pays you divident of $50", "Chance"));
  chanceOutOfJail = new Card("Get Out of Jail Free", "Chance", true);
  chanceCards.offer(chanceOutOfJail);
  chanceCards.offer(new Card("Go back 3 spaces", "Chance", -3));
  chanceCards.offer(new Card("Go to Jail", "Chance", 10, true));
  chanceCards.offer(new Card("Make general repairs on all your property", "Chance"));
  chanceCards.offer(new Card("Pay poor tax of $15", "Chance"));
  chanceCards.offer(new Card("Take a ride on the Reading Railroad", "Chance", 5));
  chanceCards.offer(new Card("Advance token to Boardwalk", "Chance", 39));
  chanceCards.offer(new Card("You have been elected Charirman of the Board", "Chance"));
  chanceCards.offer(new Card("Your building and loan matures", "Chance"));
  chanceCards.offer(new Card("You have won a crossword competition", "Chance"));

  communityChestCards.offer(new Card("Advance to Go", "Community Chest", 0));
  communityChestCards.offer(new Card("Bank error in your favor", "Community Chest"));
  communityChestCards.offer(new Card("Doctor's fees", "Community Chest"));
  communityChestCards.offer(new Card("From sale of stock you get $50", "Community Chest"));
  commChestOutOfJail = new Card("Get Out of Jail Free", "Community Chest", true);
  communityChestCards.offer(commChestOutOfJail);
  communityChestCards.offer(new Card("Go to Jail", "Community Chest", 10, true));
  communityChestCards.offer(new Card("Grand Opera opening", "Community Chest"));
  communityChestCards.offer(new Card("Xmas fund matures", "Community Chest"));
  communityChestCards.offer(new Card("Income tax refund", "Community Chest"));
  communityChestCards.offer(new Card("It is your birthday", "Community Chest"));
  communityChestCards.offer(new Card("Life insurance matures", "Community Chest"));
  communityChestCards.offer(new Card("Pay hospital fees of $100", "Community Chest"));
  communityChestCards.offer(new Card("Pay school fees of $150", "Community Chest"));
  communityChestCards.offer(new Card("Receive for Services $25", "Community Chest"));
  communityChestCards.offer(new Card("You are assessed for street repairs", "Community Chest"));
  communityChestCards.offer(new Card("You have won second prize in a beauty contest", "Community Chest"));
  communityChestCards.offer(new Card("You inherit $100", "Community Chest"));
  
}

Monopoly::~Monopoly() {
  for (int i = 0; i < players.size(); i++) {
    delete players[i];
  }
  while (chanceCards.getSize() > 0) {
    delete chanceCards.removeFirst();
  }
  while (communityChestCards.getSize() > 0) {
    delete communityChestCards.removeFirst();
  }
}

int Monopoly::roll() {
  return rand() % 6 + 1;
}

void Monopoly::visitSpace(int spaceNum) {
  if (visitCount.count(spaceNum) == 0) {
    visitCount[spaceNum] = 1;
  } else {
    visitCount[spaceNum] = visitCount[spaceNum] + 1;
  }
}

void Monopoly::sendToJail(Player* player) {
  player->moveToJail(JAIL);
  visitSpace(JAIL);
}

Card* Monopoly::handleCard(LinkedList<Card*>& deck, Player* player, bool verbose) {
  Card* card = deck.pop();
  if (verbose) {
    cout << " -> " << card->getType() << " - " << card->getName() << endl;
  }
  if (card->isOutOfJailFree()) {
    // Card is removed from the deck until played
    return card;
  }
  
  if (card->isGoToJail()) {
    sendToJail(player);
  } else {
    if (card->isAdvanceToCard()) {
      if (card->getNumAdvanceToSpaces() == 1) {
        int newSpace = card->getAdvanceToSpace()[0];
        if (newSpace >= 0) {
          player->setSpace(newSpace);
          visitSpace(newSpace);
        } else {
          // Go back 3
          newSpace = player->getSpace() + newSpace;
          player->setSpace(newSpace);
          visitSpace(newSpace);
        }
      } else {
        // advance to nearest        
        for (int i = 0; i < card->getNumAdvanceToSpaces(); i++) {
          if (player->getSpace() < card->getAdvanceToSpace()[i]) {
            player->setSpace(card->getAdvanceToSpace()[i]);
            visitSpace(card->getAdvanceToSpace()[i]);
            break;
          } else if (i == card->getNumAdvanceToSpaces() - 1 && player->getSpace() > card->getAdvanceToSpace()[i]){
            // on the last space, and player is past the last space, this player needs to go to the first space
            player->setSpace(card->getAdvanceToSpace()[0]);
            visitSpace(card->getAdvanceToSpace()[0]);
            break;
          }
        }
      }
    }
  }
  // put the card back in the deck
  deck.offer(card);
  return NULL;
}

void Monopoly::simulate(bool verbose) {
  for (int round = 1; round <= turns; round++) {
    if (verbose) {
      cout << "++++++++++++++++++++" << endl << "Starting round " << round << endl;
    }
    int roll1, roll2;
    for (int player = 0; player < players.size(); player++) {
      if (verbose) {
        cout << "Player " << player << " starting on " << board[players[player]->getSpace()] << endl;
      }
      if (players[player]->isInJail() && players[player]->hasGetOutOfJail()) {
        // Play get out of jail card
        if (players[player]->hasChanceGetOutOfJail()) {
          chanceCards.offer(chanceOutOfJail);
        } else {
          communityChestCards.offer(commChestOutOfJail);
        }
        players[player]->useOutOfJailCard();
        players[player]->setSpace(JAIL); // move them to just visiting
        if (verbose) {
          cout << "Player " << player << " used a get out of jail free card" << endl;
        }
      }

      bool turnOver = false;
      int doublesCount = 0;
      while (!turnOver) {
        roll1 = roll();
        roll2 = roll();
        if (verbose) {
          cout << "Player " << (player) << " rolls " << roll1 << "+" << roll2 << endl;
        }
        
        if (players[player]->isInJail()) {
          if (players[player]->getTurnsInJail() == 2) {
            if (verbose) {
              //cout << " - Third roll from jail, releasing." << endl;
            }
            players[player]->setSpace(JAIL);
          } else if (roll1 == roll2) {
            if (verbose) {
              cout << " - doubles, releasing from jail." << endl;
            }
            players[player]->setSpace(JAIL);
          } else {
            if (verbose) {
              cout << " - still in jail" << endl;
            }
            players[player]->addTurnInJail();
            turnOver = true;
            break;
          }
        }
        
        if (roll1 == roll2) {
          doublesCount++;
          if (doublesCount == 3) {
            if (verbose) {
              cout << "Player " << (player) << " rolled 3 doubles, go to jail." << endl;
            }
            sendToJail(players[player]);
            turnOver = true;
            continue;
          }
        } else {
          turnOver = true;
        }
        // Turn over only stays false if doubles were rolled, and it wasn't the 3rd time

        int newSpace = (players[player]->getSpace() + roll1 + roll2) % NUM_SPACES;
        if (newSpace == GO_TO_JAIL) {
          if (verbose) {
            cout << "Player " << (player) << " landed on Go To Jail" << endl;
          }
          visitSpace(GO_TO_JAIL);
          sendToJail(players[player]);
          turnOver = true;
        } else {
          players[player]->setSpace(newSpace);
          visitSpace(newSpace);
          if (verbose) {
            cout << "Player " << player << " landed on " << board[newSpace] << endl;
          }
          
          // Deal with cards
          if (chanceSpaces.count(newSpace) > 0) {
            Card* card = handleCard(chanceCards, players[player], verbose);
            if (card != NULL) {          
              players[player]->awardChanceOutOfJail();
            } else if (comChestSpaces.count(players[player]->getSpace()) > 0) {
              // update new space to the player's result space, since they get another card
              newSpace = players[player]->getSpace();
            } else if (players[player]->isInJail()) {
              // Player was moved to jail, end turn
              turnOver = true;
            }
          }
        
          if (comChestSpaces.count(newSpace) > 0) {
            Card* card = handleCard(communityChestCards, players[player], verbose);
            if (card != NULL) {
              players[player]->awardComChestOutOfJail();
            } else if (players[player]->isInJail()) {
              // Player was moved to jail, end turn
              turnOver = true;
            }
          }
        }

      }
    } 
  }
}

string Monopoly::getResults() {
  stringstream s;
  // print out the spaces and their usage
  for (int i = 0; i < board.size(); i++) {
    s << board[i] << " :: " << visitCount[i] << endl;
  }
  return s.str();
}
