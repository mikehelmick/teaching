#ifndef IS_STUDENT_H
#define IS_STUDENT_H

#include <PersonPredicate.h>
#include <Person.h>

class IsStudent : public PersonPredicate {
public:
  IsStudent();
  virtual ~IsStudent();

  virtual bool apply(Person* person) const;
};

#endif