/*
 * pizza_test.cpp
 *
 *  Created on: Oct 1, 2013
 *      Author: helmicmt
 */

#include <pizza_test.h>

#include <pizza.h>
#include <topping.h>

#include <cxxtest/TestSuite.h>

  void PizzaTest::testConstructor() {
    Pizza pizza;
    TS_ASSERT_EQUALS(0, pizza.getToppingsCount());
    TS_ASSERT_DELTA(8.99, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(0, pizza.getToppings()->size());
  }

  void PizzaTest::testAddOneTopping() {
    Pizza pizza;
    Topping* pep = new Topping("pepperoni");
    pizza.addTopping(pep);
    TS_ASSERT_EQUALS(1, pizza.getToppingsCount());
    TS_ASSERT_DELTA(10.74, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(1, pizza.getToppings()->size());
  }

  void PizzaTest::testAddOnePremiumTopping() {
    Pizza pizza;
    Topping* pep = new Topping("pepperoni", true);
    pizza.addTopping(pep);
    TS_ASSERT_EQUALS(1, pizza.getToppingsCount());
    TS_ASSERT_DELTA(10.24, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(1, pizza.getToppings()->size());
  }

  void PizzaTest::testAddTwoToppings() {
    Pizza pizza;
    Topping* pep = new Topping("pepperoni", true);
    Topping* cheese = new Topping("cheese", false);
    pizza.addTopping(pep);
    pizza.addTopping(cheese);
    TS_ASSERT_EQUALS(2, pizza.getToppingsCount());
    TS_ASSERT_DELTA(10.99, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(2, pizza.getToppings()->size());
  }


