#include "pizza.h"

Pizza::Pizza() {
  // nothing to initialize in the constructor
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
  double price = 8.99; // base price

  // for (int i = 0; i < toppings.size(); i++) {
  //  if (toppings[i].isPremium()) {

  for (vector<Topping>::iterator iter = toppings.begin(); iter != toppings.end(); iter++) {
    if (iter->isPremium()) {
      price += 1.25;
    } else {
      price += 0.75;
    }
  }
  return price;
}
