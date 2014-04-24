#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

/*
 Represents a person and their locatin in the coorinate space.
 You do not need to make any changes to this file, but you
 are free to do so, if you find it helpful.
 */

class Person {
public:
  Person();
  virtual ~Person();
  
  int getSteps() const;
  int getXPos() const;
  int getYPos() const;
  
  bool move(const string &direction, int steps);
  
private:
  int xPos;
  int yPos;
  int totalSteps;
  
  static const double NE;
  static const double SE;
  static const double SW;
  static const double NW;

  static int myRound(double val);
 
  /* True if the direction is valid, assumes that the direction is
   * already lowercase. */
  static bool validDirection(const string &direction);
  /* Returns true if steps > 0, false otherwise */
  static bool validSteps(int steps);
};

#endif