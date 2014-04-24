#ifndef PERSON_H
#define PERSON_H

class Person {
public:
  Person();
  virtual ~Person();

  virtual bool isStudent() const = 0;
  virtual bool isProfessor() const = 0;
};

#endif