/*
 * Military.h
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#ifndef MILITARY_H_
#define MILITARY_H_

#include "Clock.h"

class Military: public Clock {
public:
	Military();
	virtual ~Military();

  virtual void printTime();
};

#endif /* MILITARY_H_ */
