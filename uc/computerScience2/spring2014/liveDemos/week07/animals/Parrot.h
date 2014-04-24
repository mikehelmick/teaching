#ifndef PARROT_H
#define PARROT_H
#include <Bird.h>

class Parrot : public Bird {
public:
  Parrot();
  
  virtual ~Parrot();

  void printName();

  bool canTalk();

};

#endif
