#ifndef NOT_H
#define NOT_H

#include <PersonPredicate.h>

class Not : public PersonPredicate {
public:
  /**
   * The not predicate becomes the owner for this memory and will delete it
   * upon destruction
   */
  Not(const PersonPredicate* pred);
  virtual ~Not();

  virtual bool apply(Person* person) const;
private:
  const PersonPredicate* predicate;
  
  Not();
};

#endif