#include <iostream>

using namespace std;

void addOne(int a){
  //return a+1;
  a = a + 10;
  //return a;
}

int addOne(int a, int b){
  return a + b + 1;
}

int main(){
  int a = 5;
  cout << a << " -- " << addOne(a) << endl;
  cout << addOne(1,2) << endl;
  return 0;
}
