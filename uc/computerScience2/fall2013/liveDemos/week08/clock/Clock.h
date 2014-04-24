/*
 * Clock.h
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <ctime>

class Clock {
public:
	Clock();
	virtual ~Clock();

	Clock(const Clock &clock);

	void tickClock();

  virtual void printTime();

protected:
  time_t getTimeSnapshot();

private:
	time_t time_snapshot;
};

#endif /* CLOCK_H_ */
