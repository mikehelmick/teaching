#include <iostream>
using namespace std;

class Demo {
public:
  Demo(int x) { this->x = x; }
  Demo(Demo &that) {
    cout << "copy constructor called!!" << endl;
    this->x = that.x;
  }

private:
  int x;
};

void fun(Demo z) {

}

int main() {
  Demo myDemo(5);
  fun(myDemo);
  Demo myDemo2 = myDemo;
}
