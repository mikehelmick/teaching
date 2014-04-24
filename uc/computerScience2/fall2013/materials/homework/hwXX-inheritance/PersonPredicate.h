#ifndef PREDICATE_H
#define PREDICATE_H

#include <Person.h>

/**
 * Abstract class defining a Predicate answering questions
 * about Person objects.
 *
 * @author Mike Helmick - mike.helmick.com
 */
class PersonPredicate {
public:
  /**
   * Pure virtual function. All classes that extend praticate
   * must
   */
  virtual bool apply(Person* item) const = 0;
};

#endif