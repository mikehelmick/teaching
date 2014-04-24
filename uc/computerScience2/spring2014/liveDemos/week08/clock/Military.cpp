/*
 * Military.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#include "Military.h"

#include <iostream>
using namespace std;

Military::Military() {
  cout << "Military()" << endl;
}

Military::~Military() {
  cout << "~Military()" << endl;
}

void Military::printTime() {
  cout << "Military::printTime()" << endl;
  // Caller doesn't own this pointer, so we shouldn't delete it.
  time_t my_time_snapshot = getTimeSnapshot();
  struct tm* timeinfo = localtime(&my_time_snapshot);
  char buffer[80];
  strftime(buffer, 80, "%D %H:%M.%S", timeinfo);
  cout << buffer << endl;
}
