#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
using namespace std;

class Card {
public:
  Card(const string& name, const string& type);
  Card(const string& name, const string& type, int advanceTo);
  Card(const string& name, const string& type, int advanceTo[], int advanceToSize);
  Card(const string& name, const string& type, int advanceTo, bool goToJail);
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