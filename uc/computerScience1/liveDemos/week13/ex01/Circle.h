#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
  Circle(double radius);

  virtual ~Circle();

  double getArea() const;

  double getRadius() const;

  static int getCirlceCreationCount();

private:
  double radius;

  static int circleCount;
};

#endif
