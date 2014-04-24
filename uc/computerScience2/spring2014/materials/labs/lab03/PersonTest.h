#ifndef PERSON_TEST_H
#define PERSON_TEST_H

#include <Person.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class PersonTest : public CxxTest::TestSuite {
private:
  static void checkPositions(const Person &p, int x, int y, int steps) {
    TS_ASSERT_EQUALS(x, p.getXPos());
    TS_ASSERT_EQUALS(y, p.getYPos());
    TS_ASSERT_EQUALS(steps, p.getSteps());
  }
  
public:
  void testConstructor() {
    Person p;
    checkPositions(p, 0, 0, 0);
  }
  
  void testInvalidDir() {
    Person p;
    TS_ASSERT(!p.move("M", 10));
    checkPositions(p, 0, 0, 0);
  }

  void testInvalidSteps() {
    Person p;
    TS_ASSERT(!p.move("N", -1));
    checkPositions(p, 0, 0, 0);
  }

  void testXMovement() {
    Person p;
    p.move("N", 5);
    checkPositions(p, 0, 5, 5);
    p.move("S", 10);
    checkPositions(p, 0, -5, 15);
  }

  void testYMovement() {
    Person p;
    p.move("e", 23);
    checkPositions(p, 23, 0, 23);
    p.move("w", 4);
    checkPositions(p, 19, 0, 27);
  }

  void testMoveNE() {
    Person p;
    p.move("ne", 10);
    checkPositions(p, 8, 8, 10);
  }

  void testMoveNW() {
    Person p;
    p.move("nw", 10);
    checkPositions(p, -8, 8, 10);
  }
  
  void testMoveSE() {
    Person p;
    p.move("se", 20);
    checkPositions(p, 15, -15, 20);
  }

  void testMoveSW() {
    Person p;
    p.move("sw", 20);
    checkPositions(p, -15, -15, 20);
  }
  
  void testTour() {
    Person p;
    p.move("NE", 10);
    checkPositions(p, 8, 8, 10);
    p.move("S", 16);
    checkPositions(p, 8, -8, 26);
    p.move("NW", 22);
    checkPositions(p, -8, 8, 48);
    p.move("S", 16);
    checkPositions(p, -8, -8, 64);
    p.move("NE", 10);
    checkPositions(p, 0, 0, 74);
  }
};

#endif
