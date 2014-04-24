#include <iostream>
using namespace std;

void fun() {
  int x;
  cout << "x is " << x << endl;
  x = 27;
}

int main() {

  for (int i = 0; i < 10; i++) {
    fun();
  }

}
