package edu.uc.eecs.pizza;

import java.util.Comparator;

public final class ToppingPremiumComparator implements Comparator<Topping> {
  @Override
  public int compare(Topping o1, Topping o2) {
    if (o1.isPremium() && !o2.isPremium()) {
      return -1;
    } else if (!o1.isPremium() && o2.isPremium()) {
      return 1;
    } else {
      // isPreimum is the same
      return o1.compareTo(o2);
    }
  }
}