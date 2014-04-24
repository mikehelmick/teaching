#include "topping.h"

#include <string>
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

string Topping::getName() {
  return name;
}

bool Topping::isPremium() {
  return premium;
}

