#ifndef STUDENT_H
#define STUDENT_H

#include <Person.h>

class Student : public Person {
public:
  Student();
  virtual ~Student();

  virtual bool isStudent() const;
  virtual bool isProfessor() const;
};

#endif