#ifndef IS_PROFESSOR_H
#define IS_PROFESSOR_H

#include <PersonPredicate.h>
#include <IsStudent.h>
#include <Person.h>

class IsProfessor : public PersonPredicate {
public:
  IsProfessor();
  virtual ~IsProfessor();

  virtual bool apply(Person* person) const;
};

#endif