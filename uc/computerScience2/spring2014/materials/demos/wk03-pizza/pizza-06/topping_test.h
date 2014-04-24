#include <topping.h>

#include <cxxtest/TestSuite.h>

class ToppingTest : public CxxTest::TestSuite {
public:
  void testNonPreimumByDefault() {
    Topping topping("cheese");
    TS_ASSERT(!topping.isPremium());
  }

  void testConstructor() {
    Topping topping("Super Ham", true);
    TS_ASSERT(topping.isPremium());
  }

  void testGetName() {
    Topping topping("pepperoni");
    TS_ASSERT_EQUALS("pepperoni", topping.getName());
  }
};