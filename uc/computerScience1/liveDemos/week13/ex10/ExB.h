#ifndef EXB_H
#define EXB_H

#include <ExC.h>

class ExB {
public:
  ExB();

  ExB(const ExB &that);

  virtual ~ExB();

private:
  ExC* myExC;
};

#endif
