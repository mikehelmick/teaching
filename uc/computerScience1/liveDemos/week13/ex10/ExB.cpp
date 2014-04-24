#include <iostream>
using namespace std;
#include <ExB.h>
#include <ExC.h>

ExB::ExB() {
  cout << "ExB::ExB()" << endl;
  myExC = new ExC();
}

ExB::ExB(const ExB &that) {
  cout << "ExB::ExB(ExB&)" << endl;
  myExC = new ExC(*(that.myExC));
}

ExB::~ExB() {
  cout << "ExB::~ExB()" << endl;
  delete myExC;
}

