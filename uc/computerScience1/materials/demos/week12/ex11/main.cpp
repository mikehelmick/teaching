
#include <iostream>
using namespace std;

class Test {
public:
  Test() {
    cout << "Constructor called." << endl;
  }

  virtual ~Test() {
    cout << "Destructor called." << endl;
  }

private:

};

int main() {
  {
  	cout << "non-pointer version" << endl;
  	Test a;
  }

  {
  	cout << "pointer version" << endl;
  	Test* b = new Test();
  	delete b;
  }
}
