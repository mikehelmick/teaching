#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include <County.h>

County::County(string line, string state) {
  int index = 0;
  for (int i = 0; i < line.size(); i++) {
  	if (line[i] == ',') {
  	  if (index == 0) {
  	  	index = i;
  	  }
  	  line[i] = ' ';
  	}
  }
  this->county = line.substr(0, index);
  this->state = state;


  stringstream ss(line.substr(index + 1));
  ss >> rVote;
  ss >> dVote;
  ss >> oVote;
}

string County::getCounty() {
  return county;
}

string County::getState() {
  return state;
}

int County::getRVote() {
  return rVote;
}

int County::getDVote() {
  return dVote;
}

int County::getOVote() {
  return oVote;
}
