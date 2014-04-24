#ifndef EXC_H
#define EXC_H

class ExC {
public:
  ExC();

  ExC(ExC &that);

  virtual ~ExC();

private:
  int* myInt;
};

#endif
