/**
 * Implementation of the Person class.
 */
#include <cmath>
#include <string>
#include <algorithm>

#include <Person.h>

using namespace std;

const double Person::NE = M_PI / 4.0;
const double Person::SE = 2 * M_PI - M_PI / 4.0;
const double Person::SW = M_PI + M_PI / 4.0;
const double Person::NW = M_PI - M_PI / 4.0;

Person::Person() : xPos(0), yPos(0), totalSteps(0) {
}

Person::~Person() {
  // Nothing to do
}
  
int Person::getSteps() const {
  return totalSteps;
}

int Person::getXPos() const {
  return xPos; 
}

int Person::getYPos() const {
  return yPos;
}

int Person::myRound(double val) {
  if (val > 0) {
    return (int) ceil(val);
  } else if (val < 0) {
    return (int) floor(val);
  }
  return 0;
}
  
bool Person::move(const string &direction, int steps) {
  string lowerDir(direction);
  transform(lowerDir.begin(), lowerDir.end(), lowerDir.begin(), tolower);
  if (!(validDirection(lowerDir) && validSteps(steps))) {
    return false;
  }

  // Total steps always goes up by "steps"
  totalSteps += steps;
  // TODO(you): increment xPos and yPos correctly, depending on the value of "lowerDir"
  // the direction has already been lowercased for you.
  
  if (lowerDir == "n") {
    yPos += steps;
  } else if (lowerDir == "s") {
    yPos -= steps;
  } else if (lowerDir == "e") {
    xPos += steps;
  } else if (lowerDir == "w") {
    xPos -= steps;
  } else if (lowerDir == "ne") {
    int xD = myRound(steps * cos(NE));
    int yD = myRound(steps * sin(NE));
    xPos += xD;
    yPos += yD;
  } else if (lowerDir == "nw") {
    int xD = myRound(steps * cos(NW));
    int yD = myRound(steps * sin(NW));
    xPos += xD;
    yPos += yD;
  } else if (lowerDir == "se") {
    int xD = myRound(steps * cos(SE));
    int yD = myRound(steps * sin(SE));
    xPos += xD;
    yPos += yD;
  } else if (lowerDir == "sw") {
    int xD = myRound(steps * cos(SW));
    int yD = myRound(steps * sin(SW));
    xPos += xD;
    yPos += yD;
  }

  return true;
}

bool Person::validDirection(const string &direction) {
  return direction == "n" || direction == "s"
      || direction == "e" || direction == "w"
      || direction == "ne" || direction == "nw"
      || direction == "se" || direction == "sw";
}

bool Person::validSteps(int steps) {
  return steps > 0;
}
