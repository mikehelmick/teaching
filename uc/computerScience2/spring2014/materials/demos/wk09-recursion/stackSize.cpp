#include <iostream>

using namespace std;

/* With no optimizations, this goes 262088 times.
    With -O2 or -O3 it will go forever!
*/

int myFunc(int n){
  cout << "Called times: " << n << endl;
  if(n == 4000000){
    return 1;
  }
  int i = 1;
  //return myFunc(n+1) + 1; // Constant OK!?!?
  //return myFunc(n+1) + i;
  int m = 0;
  if( n%2 ==0){
    m = myFunc(n+1);
  }else{
    m = myFunc(n+1);
  }
  return m + i;
}

int main(){
  cout << myFunc(1);
}