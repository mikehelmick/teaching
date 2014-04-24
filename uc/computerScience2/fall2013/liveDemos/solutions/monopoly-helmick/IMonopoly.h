#ifndef IMONOPOLY_H
#define IMONOPOLY_H

#include <string>
using namespace std;

class IMonopoly {
public:
  IMonopoly(int players, int turns) : players(players), turns(turns) {
    
  }
  virtual ~IMonopoly() {
    
  }
  
  virtual void simulate(bool verbose) = 0;
  
  virtual string getResults() = 0;

protected:
  int players;
  int turns;

private:
  IMonopoly();
};

#endif