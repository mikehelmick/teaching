#include <iostream>
using namespace std;
#include <ExA.h>
#include <ExB.h>

ExA::ExA() {
  cout << "ExA::ExA()" << endl;
  myExB = new ExB();
}

ExA::ExA(const ExA &that) {
  cout << "ExA::ExA(ExA&)" << endl;
  myExB = new ExB(*(that.myExB));
}

ExA::~ExA() {
  cout << "ExA::~ExA()" << endl;
  delete myExB;
}

