/*
 * Oval.h
 *
 *  Created on: Feb 24, 2014
 *      Author: student
 */

#ifndef OVAL_H_
#define OVAL_H_

#include "Shape.h"
#include <cmath>

class Oval: public Shape {
public:
  Oval(double a, double b);
  virtual ~Oval();

  virtual double area() const;
  virtual double primater() const;

  virtual bool isEqual(Shape* rhs) const;

protected:
  const double getA() const;

private:
   double a;
   double b;
};

#endif /* OVAL_H_ */
