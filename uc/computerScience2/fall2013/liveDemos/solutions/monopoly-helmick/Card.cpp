#include <Card.h>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

Card::Card(const string& name, const string& type)
    : name(name), type(type), advance(false), goToJail(false), outOfJail(false) {
}

Card::Card(const string& name, const string& type, int advanceTo)
    : name(name), type(type), advance(true), goToJail(false), outOfJail(false) {
  advanceToSpaces.push_back(advanceTo);
}
  
Card::Card(const string& name, const string& type, int advanceTo[], int advanceToSize)
    : name(name), type(type), advance(true), goToJail(false), outOfJail(false) {
  for (int i = 0; i < advanceToSize; i++) {
    advanceToSpaces.push_back(advanceTo[i]);
  }
  sort(advanceToSpaces.begin(), advanceToSpaces.end());
}

Card::Card(const string& name, const string& type, int advanceTo, bool goToJail)
    : name(name), type(type), advance(true), goToJail(true), outOfJail(false) {
  advanceToSpaces.push_back(advanceTo);
}

Card::Card(const string& name, const string& type, bool getOutOfJailCard)
    : name(name), type(type), advance(false), goToJail(false), outOfJail(true) {
}

Card::~Card() {
  // nothing
}

string Card::getName() {
  return name;
}

string Card::getType() {
  return type;
}

bool Card::isGoToJail() const {
  return goToJail;
}

bool Card::isOutOfJailFree() const {
  return outOfJail;
}

bool Card::isAdvanceToCard() const {
  return advance;
}

vector<int> Card::getAdvanceToSpace() const {
  return advanceToSpaces;  
}

int Card::getNumAdvanceToSpaces() const {
  return advanceToSpaces.size();
}