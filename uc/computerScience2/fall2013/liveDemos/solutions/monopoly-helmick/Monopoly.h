#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <IMonopoly.h>
#include <Player.h>
#include <Card.h>
#include <LinkedList.h>

#include <map>
#include <set>
using namespace std;

/*
 * Main monopoly simulation driver.
 */
class Monopoly : public IMonopoly {
public:
  // Creates a new monopoply simulation.
  Monopoly(int players, int turns);
  virtual ~Monopoly();
  
  void simulate(bool verbose);
  
  string getResults();
  
private:
  vector<Player*> players;
  Queue<Card*>* chanceCards;
  Queue<Card*>* communityChestCards;

  Card* chanceOutOfJail;
  Card* commChestOutOfJail;

  map<int, long> visitCount;

  vector<string> board;
  set<int> comChestSpaces;
  set<int> chanceSpaces;
  static const int GO_TO_JAIL;
  static const int JAIL;
  static const int NUM_SPACES;

  int roll();
  void visitSpace(int spaceNum);
  void sendToJail(Player* player);
  Card* handleCard(Queue<Card*>* deck, Player* player, bool verbose);
};

#endif