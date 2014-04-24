/*
 * Rectangle.h
 *
 *  Created on: Feb 24, 2014
 *      Author: student
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape {
public:
  Rectangle(double length, double width);
  virtual ~Rectangle();

  virtual double area() const;
  virtual double primater() const;

  virtual bool isEqual(Shape* rhs) const;

protected:
  const double getLength() const;
  const double getWidth() const;

private:
  double length;
  double width;
};

#endif /* RECTANGLE_H_ */
