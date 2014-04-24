#include<iostream>
using namespace std;

void square(int& input) {
  input = input * input;
}

int square_ref(const int& input) {
  return input * input;
}

int main() {
  int x = 42; 
  int tmp_x = x;
  cout << "x=" << x << endl;
  square(tmp_x);
  cout << "function called" << endl;
  cout << "x=" << x << " tmp_x=" << tmp_x << endl;
}
