#ifndef PIZZA_TEST_H
#define PIZZA_TEST_H

#include <pizza.h>

#include <cxxtest/TestSuite.h>

class PizzaTest : public CxxTest::TestSuite {
public:
  void testConstructor();
  void testAddOneTopping();
  void testAddOnePremiumTopping();
  void testAddTwoToppings();
};

#endif
