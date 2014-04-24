#include "pizza.h"

Pizza::Pizza() {
  // nothing to initialize in the constructor
}

Pizza::~Pizza() {
  for (unsigned int i = 0; i < toppings.size(); i++) {
	  delete toppings[i];
  }
}
 
void Pizza::addTopping(Topping* topping) {
  this->toppings.push_back(topping);
}

const vector<Topping*>* Pizza::getToppings() {
  return &toppings;
}

int Pizza::getToppingsCount() {
  return toppings.size();
}

double Pizza::getPrice() {
  double price = 8.99; // base price
  for (vector<Topping*>::iterator iter = toppings.begin(); iter != toppings.end(); iter++) {
    if ((*iter)->isPremium()) {
      price += 1.25;
    } else {
      price += 0.75;
    }
  }
  return price;
}
