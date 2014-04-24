#ifndef SHIP_TEST_H
#define SHIP_TEST_H

#include <ship.h>

#include <cxxtest/TestSuite.h>

class ShipTest : public CxxTest::TestSuite {
public:
  
  void testConstructor() {
    Ship myShip(2);
  }

  void testGetSize() {
    Ship myShip(6);
    TS_ASSERT_EQUALS(6, myShip.getSize());
  }
};

#endif