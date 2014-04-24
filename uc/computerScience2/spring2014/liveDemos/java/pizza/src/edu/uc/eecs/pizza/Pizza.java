package edu.uc.eecs.pizza;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Pizza {
    public static final double BASE_PRICE = 8.99;
  private static int pizzaCount = 0;
  
  private List<Topping> toppings = new SortedList<Topping>();
  
  public Pizza() {
    pizzaCount++; // increment static counter
  }

  public void addTopping(Topping topping) {
    toppings.add(topping);
  }

  public List<Topping> getToppings() {
    return new ArrayList<Topping>(toppings);
  }
  
  public List<Topping> getToppingsPremiumFirst() {
    List<Topping> toppins = new ArrayList<Topping>(toppings);
    Collections.sort(toppins, new ToppingPremiumComparator());
    return toppins;
  }

  public int getToppingsCount() {
    return toppings.size();
  }
  
  /**
   * Calculates the prize of the pizza with the currently selected toppings.
   * Regular toppings att $0.75 to the price.
   * Premium toppings att $1.25 to the price.
   */
  public double getPrice() {
    double price = BASE_PRICE;
    for (Topping topping : toppings) {
      if (topping.isPremium()) {
        price += 1.25;
      } else {
        price += 0.75;
      }
    }
    return price;
  }

  public static int getTotalPizzaCount() {
    return pizzaCount;
  }
}
