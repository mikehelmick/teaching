// week13/ex03
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
  Circle(double radius);

  // Copy constructor
  Circle(const Circle &that);

  Circle& operator=(const Circle &rhs);

  virtual ~Circle();

  double getArea() const;

  double getRadius() const;

  static int getCircleCreationCount();

private:
  double radius;

  static int circleCount;
};

#endif
