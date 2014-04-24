#include <pizza.h>
#include <topping.h>

#include <cxxtest/TestSuite.h>

class PizzaTest : public CxxTest::TestSuite {
public:
  void testConstructor() {
    Pizza p;
    TS_ASSERT_EQUALS(0, p.getToppingsCount());
    TS_ASSERT_DELTA(8.99, p.getPrice(), 0.001);
  }

  void testAddTopping() {
    Topping t("Extra Cheese", true);
    Pizza p;
    p.addTopping(t);

    TS_ASSERT_EQUALS(1, p.getToppingsCount());
    TS_ASSERT_DELTA(8.99 + 1.25, p.getPrice(), 0.001);
  }

  void testGetPrice() {
    Topping t("Extra Cheese", true);
    Pizza p;
    p.addTopping(t);

    TS_ASSERT_EQUALS(1, p.getToppingsCount());
    TS_ASSERT_DELTA(8.99 + 1.25, p.getPrice(), 0.001);

    Topping t2("Pep", false);
    p.addTopping(t2);
    TS_ASSERT_EQUALS(2, p.getToppingsCount());
    TS_ASSERT_DELTA(8.99 + 1.25 + 0.75, p.getPrice(), 0.001);
  }

  void testGetToppingsNone() {
    Pizza p;

    vector<Topping> toppings = p.getToppings(); 
    TS_ASSERT_EQUALS(0, toppings.size());
  }

  void testGetToppings() {
    Topping t1("Extra Cheese", true);
    Topping t2("Pepper");

    Pizza p;
    p.addTopping(t1);
    p.addTopping(t2); 
    
    vector<Topping> toppings = p.getToppings();
    TS_ASSERT_EQUALS(2, toppings.size());
    TS_ASSERT_EQUALS("Extra Cheese", toppings[0].getName());
    TS_ASSERT_EQUALS("Pepper", toppings[1].getName());
  }
};
