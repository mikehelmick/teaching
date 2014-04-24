/*
 * Shape.h
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
  Shape();
  virtual ~Shape();

  virtual double area() const = 0;
  virtual double primater() const = 0;

  virtual bool isEqual(Shape* rhs) const = 0;

protected:
  bool doubleIsEqual(double a, double b, double delta) const;
};

#endif /* SHAPE_H_ */
