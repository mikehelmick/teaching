#include "pizza.h"


Pizza::Pizza() {
  // Nothing to do
}

void Pizza::addTopping(Topping topping) {
  toppings.push_back(topping);
}

vector<Topping> Pizza::getToppings() {
  return toppings;
}

int Pizza::getToppingsCount() {
  return toppings.size();
}

double Pizza::getPrice() {
  double price = 0.0;
  for (vector<Topping>::iterator it = toppings.begin() ;
      it != toppings.end(); it++) {
    if (it->isPremium()) {
      price += 1.25;
    } else {
      price += 0.75;
    }
  }
  return price;
}








