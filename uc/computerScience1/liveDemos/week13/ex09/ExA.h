#ifndef EXA_H
#define EXA_H

#include <ExB.h>

class ExA {
public:
  ExA();

  virtual ~ExA();

private:
  ExB* myExB;
};

#endif
