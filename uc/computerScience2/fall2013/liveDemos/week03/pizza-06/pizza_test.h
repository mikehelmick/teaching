#include <pizza.h>

#include <cxxtest/TestSuite.h>

class PizzaTest : public CxxTest::TestSuite {
public:
  void testConstructor() {
    Pizza pizza;
    TS_ASSERT_EQUALS(0, pizza.getToppingsCount());
    TS_ASSERT_DELTA(8.99, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(0, pizza.getToppings().size());
  }

  void testAddOneTopping() {
    Pizza pizza;
    Topping pep("pepperoni");
    pizza.addTopping(pep);
    TS_ASSERT_EQUALS(1, pizza.getToppingsCount());
    TS_ASSERT_DELTA(9.74, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(1, pizza.getToppings().size());
  }

  void testAddOnePremiumTopping() {
    Pizza pizza;
    Topping pep("pepperoni", true);
    pizza.addTopping(pep);
    TS_ASSERT_EQUALS(1, pizza.getToppingsCount());
    TS_ASSERT_DELTA(10.24, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(1, pizza.getToppings().size());
  }

  void testAddTwoToppings() {
    Pizza pizza;
    Topping pep("pepperoni", true);
    Topping cheese("cheese", false);
    pizza.addTopping(pep);
    pizza.addTopping(cheese);
    TS_ASSERT_EQUALS(2, pizza.getToppingsCount());
    TS_ASSERT_DELTA(10.99, pizza.getPrice(), 0.01);
    TS_ASSERT_EQUALS(2, pizza.getToppings().size());
  }
};
