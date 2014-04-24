/*
 * main.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */


#include <Clock.h>
#include <Military.h>

#include <vector>
#include <iostream>
using namespace std;

void printAndTick(vector<Clock*> &clocks) {
  for (unsigned int i = 0; i < clocks.size(); i++) {
    Clock* curClock = clocks[i];
    curClock->printTime();
    curClock->tickClock();
    curClock->printTime();
  }
}

int main() {
  vector<Clock*> myClocks;
  
  myClocks.push_back(new Clock());
  myClocks.push_back(new Military());
  
  printAndTick(myClocks);
  
  // CLEAN UP MY MEMORY!!!
  for (unsigned int i = 0; i < myClocks.size(); i++) {
    delete myClocks[i];
  }
}
