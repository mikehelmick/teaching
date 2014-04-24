// week13/ex08/Point.h
#ifndef POINT_H
#define POINT_H

#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Point {
public:
  // Create a new point, with location x,y
  Point(double x, double y);

  Point(const Point &that);

  virtual ~Point();

  double getX() const;

  double getY() const;

  // Compute the straight line distance between this point
  // and the point passed in
  double distance(const Point& that);

  string toString() const;

private:
  double* x;
  double* y;
};

#endif
