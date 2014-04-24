package edu.uc.eecs.pizza;

public class Topping implements Comparable<Topping> {
  private String name;
  private boolean premium;
  
  Topping(String name, boolean isPremium) {
    this.name = name;
    this.premium = isPremium;
  }

  Topping(String name) {
    this(name, false);
  }
  
  String getName() {
    return name;
  }

  boolean isPremium() {
    return premium;
  }

  @Override
  public int compareTo(Topping that) {
    return this.name.compareTo(that.name);
  }
  
  @Override
  public String toString() {
    return name + " " + premium;
  }
}
