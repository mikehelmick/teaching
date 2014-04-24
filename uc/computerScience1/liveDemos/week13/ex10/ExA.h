#ifndef EXA_H
#define EXA_H

#include <ExB.h>

class ExA {
public:
  ExA();

  ExA(const ExA &that);

  virtual ~ExA();

private:
  ExB* myExB;
};

#endif
