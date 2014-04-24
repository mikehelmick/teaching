#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <Person.h>

class Professor : public Person {
public:
  Professor();
  virtual ~Professor();

  virtual bool isStudent() const;
  virtual bool isProfessor() const;
};

#endif