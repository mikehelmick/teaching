// e08/Point.h
#ifndef POINT_H
#define POINT_H
 
#include <string>
using namespace std;

class Point {
public:
  Point(double x, double y);

  double getX() const;

  double getY() const;

  double distance(const Point& that);

  string toString() const;

private:
  double x;
  double y;
};

#endif
