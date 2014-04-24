#ifndef AND_H
#define AND_H

#include <PersonPredicate.h>

class And : public PersonPredicate {
public:
  /**
   * The and predicate becomes the owner for this memory and will delete it
   * upon destruction
   */
  And(const PersonPredicate* predA, const PersonPredicate* predB);
  virtual ~And();

  virtual bool apply(Person* person) const;
private:
  const PersonPredicate* predA;
  const PersonPredicate* predB;
  
  And();
};

#endif