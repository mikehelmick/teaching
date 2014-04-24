#include <iostream>

using namespace std;

int main(){
  int a = 5;
  while(1){
    if(a % 1000 == 0){
      cout << "a: " << a << endl;
    }
    a++;
  }
  return 0;
}
