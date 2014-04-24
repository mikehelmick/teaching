#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
using namespace std;

/* Represents a single chance or community chest card */
class Card {
public:
  // Basic card, no actions
  Card(const string& name, const string& type);
  // Card that can advance to a specific space (or negative if relative)
  Card(const string& name, const string& type, int advanceTo);
  // Card that can advance to a range of spaces (i.e. nearest railroad)
  Card(const string& name, const string& type, int advanceTo[], int advanceToSize);
  // Card that sends you to jail
  Card(const string& name, const string& type, int advanceTo, bool goToJail);
  // Represents a get out of jail free card
  Card(const string& name, const string& type, bool getOutOfJailCard);
  virtual ~Card();

  string getName();
  string getType();
  
  bool isGoToJail() const;
  bool isOutOfJailFree() const;
  
  bool isAdvanceToCard() const;
  vector<int> getAdvanceToSpace() const;
  int  getNumAdvanceToSpaces() const;
  
private:
  string name;
  string type;
  bool advance;
  vector<int> advanceToSpaces;
  bool goToJail;
  bool outOfJail;
};

#endif