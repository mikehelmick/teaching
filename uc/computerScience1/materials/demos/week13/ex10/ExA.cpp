#include <iostream>
using namespace std;

#include <ExA.h>

ExA::ExA() {
  cout << "ExA::ExA()" << endl;
  myExB = new ExB();
}

ExA::ExA(ExA &that) {
  cout << "ExA::ExA(ExA)" << endl;
  myExB = new ExB(*(that.myExB));
}

ExA::~ExA() {
  cout << "ExA::~ExA()" << endl;
  delete myExB;
}
