#ifndef PIZZA_H
#define PIZZA_H

#include "topping.h"
#include <vector>

using namespace std;

/**
 * Represents a pizza!
 */
class Pizza {

public:
  /**
   * Creates a new pizza
   */
  Pizza();

  /**
   * @param topping the topping to add to this pizza, can be a duplicate
   */ 
  void addTopping(Topping topping);

  /**
   * Returns a collection of the topings that have been added to this pizza.
   */
  vector<Topping> getToppings();

  /**
   * Returns the number of toppings that have been added to this pizza.
   */ 
  int getToppingsCount();
  
  /**
   * Calculates the prize of the pizza with the currently selected toppings.
   * Regular toppings at $0.75 to the price.
   * Premium toppings at $1.25 to the price.
   */
  double getPrice();

private:
  vector<Topping> toppings;
};

#endif








