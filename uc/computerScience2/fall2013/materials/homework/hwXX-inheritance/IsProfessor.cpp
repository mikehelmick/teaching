#include <IsProfessor.h>

IsProfessor::IsProfessor() {

}

IsProfessor::~IsProfessor() {

}

bool IsProfessor::apply(Person* person) const {
  return person->isProfessor();
}