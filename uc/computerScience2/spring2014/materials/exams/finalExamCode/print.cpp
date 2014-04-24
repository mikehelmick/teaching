#include <iostream>
using namespace std;

class B {
public:
  void print(int n) const {
    cout << n << endl;
  }
};

class D : public B {
public:
  void print(int n) const {
    if (n <= 1) {
      B::print(n);
    } else if (n % 2 == 0) {
      cout << n << " ";
      print(n / 2);
    } else {
      cout << n << " ";
      print(3 * n + 1);
    }
  }
};

int main() {
  D d;
  d.print(1);
  d.print(5);
  
  B b;
  b.print(1);
  b.print(5);
  
  return 0;
}