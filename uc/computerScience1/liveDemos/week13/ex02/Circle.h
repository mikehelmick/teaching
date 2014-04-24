#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
  Circle(double radius);

  Circle(Circle &other);

  virtual ~Circle();

  double getArea() const;

  double getRadius() const;

  static int getCircleCreationCount();

private:
  double radius;

  static int circleCount;
};

#endif
