/*
 * Clock.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#include "Clock.h"

#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

Clock::Clock() {
  cout << "Clock()" << endl;
  time(&time_snapshot);
}

Clock::Clock(const Clock &clock) {
  cout << "Clock(Clock&)" << endl;
  this->time_snapshot = clock.time_snapshot;
}

Clock::~Clock() {
  cout << "~Clock()" << endl;
}

void Clock::tickClock() {
  cout << "Clock::tickClock()" << endl;
  sleep(1);
  time(&time_snapshot);
}

time_t Clock::getTimeSnapshot() {
  return time_snapshot;
}

void Clock::printTime() {
  cout << "Clock::printTime()" << endl;
  // Caller doesn't own this pointer, so we shouldn't delete it.
  struct tm* timeinfo = localtime(&time_snapshot);
  char buffer[80];
  strftime(buffer, 80, "%D %I:%M.%S %p", timeinfo);
  cout << buffer << endl;
}
