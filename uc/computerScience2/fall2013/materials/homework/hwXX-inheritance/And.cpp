#include <And.h>

And::And() {

}

And::And(const PersonPredicate* predA, const PersonPredicate* predB) : predA(predA), predB(predB) {
}

And::~And() {
  delete predA;
  delete predB;
}

bool And::apply(Person* person) const {
  return predA->apply(person) && predB->apply(person);
}
