package edu.uc.eecs.pizza;

import static org.junit.Assert.*;

import org.junit.Test;

public class ToppingTest {

  @Test
  public void testGetName() {
    Topping topping = new Topping("Pepperoni", false);
    assertEquals("Pepperoni", topping.getName());
  }

  @Test
  public void testIsPremium() {
    Topping topping = new Topping("Pepperoni", false);
    assertFalse(topping.isPremium());
  }

  @Test
  public void testIsPremiumTrue() {
    Topping topping = new Topping("Pepperoni", true);
    assertTrue(topping.isPremium());
  }
}
