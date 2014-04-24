#ifndef COUNTY_H
#define COUNTY_H

#include <string>
using namespace std;

class County {
public:
  County(string line, string state);

  string getCounty();

  string getState();

  int getRVote();

  int getDVote();

  int getOVote();

private:
  string county;
  string state;
  int rVote;
  int dVote;
  int oVote;
};

#endif