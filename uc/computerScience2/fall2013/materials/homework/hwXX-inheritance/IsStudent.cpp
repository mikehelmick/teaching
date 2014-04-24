#include <IsStudent.h>

IsStudent::IsStudent() {
  
}

IsStudent::~IsStudent() {
  
}

bool IsStudent::apply(Person* person) const {
  return person->isStudent();
}