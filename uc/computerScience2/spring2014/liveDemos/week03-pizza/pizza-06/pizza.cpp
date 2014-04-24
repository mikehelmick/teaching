#include "pizza.h"

const double Pizza::BASE_PRICE = 8.99;

int Pizza::totalPizzaCount = 0;

Pizza::Pizza() {
  // nothing to initialize in the constructor
  totalPizzaCount++;
}

int Pizza::getTotalPizzaCount() {
  return totalPizzaCount;
}
 
void Pizza::addTopping(Topping topping) {
  this->toppings.push_back(topping);
}

vector<Topping> Pizza::getToppings() {
  return toppings;
}

int Pizza::getToppingsCount() {
  return toppings.size();
}

double Pizza::getPrice() {
  double price = BASE_PRICE; // base price
  for (vector<Topping>::iterator iter = toppings.begin(); iter != toppings.end(); iter++) {
    if (iter->isPremium()) {
      price += 1.25;
    } else {
      price += 0.75;
    }
  }
  return price;
}
