package edu.uc.eecs.pizza;

import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class PizzaTest {
  
  @Test
  public void testConstructor() {
    Pizza p = new Pizza();
    assertEquals(0, p.getToppingsCount());
    assertEquals(8.99, p.getPrice(), 0.001);
  }

  @Test
  public void testAddTopping() {
    Topping t = new Topping("Extra Cheese", true);
    Pizza p = new Pizza();
    p.addTopping(t);

    assertEquals(1, p.getToppingsCount());
    assertEquals(8.99 + 1.25, p.getPrice(), 0.001);
  }
  
  @Test
  public void testSortByPremiumFirst() {
    Pizza p = new Pizza();
    p.addTopping(new Topping("one", true));
    p.addTopping(new Topping("two", false));
    p.addTopping(new Topping("three", true));
    p.addTopping(new Topping("four", false));
    
    List<Topping> toppings = p.getToppingsPremiumFirst();
    for (Topping topping : toppings) {
      System.out.println(topping);
    }
  }
}
