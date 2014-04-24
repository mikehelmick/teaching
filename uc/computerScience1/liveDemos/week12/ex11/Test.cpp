#include <iostream>
using namespace std;

class Test {
public:
  Test() {
    cout << "Test::Test()" << endl;
  }

  virtual ~Test() {
    cout << "Test::~Test()" << endl;
  }

private:

};

int main() {
  {
    cout << "non-pointer version" << endl;
    Test a;
    cout << "ending example" << endl;
  }
  cout << "*example is done*" << endl;

  {
    cout << "pointer version" << endl;
    Test* b = new Test();
    cout << "ending example" << endl;
    delete b;
  }
  cout << "*example is done*" << endl;

}
