#include <iostream>
using namespace std;
#include <ExB.h>
#include <ExC.h>

ExB::ExB() {
  cout << "ExB::ExB()" << endl;
  myExC = new ExC();
}

ExB::~ExB() {
  cout << "ExB::~ExB()" << endl;
  delete myExC;
}

