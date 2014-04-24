#include <iostream>
using namespace std;
#include <ExA.h>
#include <ExB.h>

ExA::ExA() {
  cout << "ExA::ExA()" << endl;
  myExB = new ExB();
}

ExA::~ExA() {
  cout << "ExA::~ExA()" << endl;
  delete myExB;
}

