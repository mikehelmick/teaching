#include "topping.h"

Topping::Topping() {
  // private, doesn't do anything
}

Topping::Topping(string newName, bool isPremium) {
  name = newName;
  premium = isPremium;
}

string Topping::getName() {
  return name;
}

bool Topping::isPremium() {
  return premium;
}

