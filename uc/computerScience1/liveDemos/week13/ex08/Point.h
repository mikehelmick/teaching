#ifndef POINT_H
#define POINT_H

#include <string>
using namespace std;

class Point {
public:
  Point(double x, double y);

  Point(const Point &that);

  virtual ~Point();

  double getX() const;

  double getY() const;

  double distance(const Point& that) const;

  string toString() const;
private:
  double* x;
  double* y;
};

#endif
