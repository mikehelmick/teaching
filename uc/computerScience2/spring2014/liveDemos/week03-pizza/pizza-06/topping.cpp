#include "topping.h"
#include <iostream>
using namespace std;

Topping::Topping() {
  // Nothing. The default constructor is not used.
}

Topping::Topping(string newName, bool isPremium) : name(newName) {
  premium = isPremium;
}

Topping::Topping(string newName) : name(newName) {
  premium = false;
}

Topping::~Topping() {
  // nothing to do.
}

string Topping::getName() {
  return name;
}

bool Topping::isPremium() {
  return premium;
}
