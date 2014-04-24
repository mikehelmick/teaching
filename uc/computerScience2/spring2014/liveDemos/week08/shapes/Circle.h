/*
 * Circle.h
 *
 *  Created on: Feb 24, 2014
 *      Author: student
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Oval.h"

class Circle: public Oval {
public:
  Circle(double r);
  virtual ~Circle();

  virtual bool isEqual(Shape* rhs) const;
};

#endif /* CIRCLE_H_ */
