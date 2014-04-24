
#include <PersonPredicate.h>
#include <Person.h>
#include <Student.h>
#include <Professor.h>
#include <IsStudent.h>
#include <IsProfessor.h>

#include <vector>
#include <iostream>

using namespace std;

vector<Person*> filter(vector<Person*> data, const PersonPredicate* predicate) {
  vector<Person*> filtered;
  for (unsigned int i = 0; i < data.size(); i++) {
    if (predicate->apply(data[i])) {
      filtered.push_back(data[i]);
    }
  }
  return filtered;
}

vector<Person*> init(int size) {
  vector<Person*> people;
  for (int i = 0; i < size; i++) {
    if (i % 15 == 0) {
      people.push_back(new Professor());
    } else {
      people.push_back(new Student());
    }
  }
  return people;
}

void cleanup(vector<Person*> data) {
  for (unsigned int i = 0; i < data.size(); i++) {
    delete data[i]; 
  }
}

int main(int argc, char* argv[]) {
  
  vector<Person*> people = init(43000);

  PersonPredicate* predicate = new IsStudent();
  vector<Person*> students = filter(people, predicate);
  delete predicate;
  predicate = new IsProfessor();
  vector<Person*> professors = filter(people, predicate);
  
  cout << "    Num people: " << people.size() << endl;
  cout << "  Num students: " << students.size() << endl;
  cout << "Num professors: " << professors.size() << endl;
  
  return 0;
}