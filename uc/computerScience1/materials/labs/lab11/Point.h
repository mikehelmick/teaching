#ifndef POINT_H
#define POINT_H

#include <string>
using namespace std;

class Point {
public:
  Point(string line);

  Point(double x, double y);

  void setX(double x);

  void setY(double y);

  double getX();

  double getY();

private:
  double x;
  double y;
};

#endif