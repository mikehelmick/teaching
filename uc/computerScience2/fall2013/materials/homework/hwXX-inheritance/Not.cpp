#include <Not.h>

Not::Not() {

}

Not::Not(const PersonPredicate* pred) : predicate(pred) {
}

Not::~Not() {
  delete predicate;
}

bool Not::apply(Person* person) const {
  return !predicate->apply(person);
}
