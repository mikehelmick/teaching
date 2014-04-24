/*
 * fact.cpp
 * Paul Talaga
 * 
 * A recursive version of the factorial function.
 * Oct 21 , 2013
 */

#include <iostream>
#include <cstdlib>

using namespace std;


int fact(int num){
  if(num <= 1){     // Base case is 1!  Make sure not to think base case is 0 since 0xanything is 0
    return 1;
  }
  return num * fact(num-1);
}

int main(int argc, char* argv[]){
  if(argc <= 1){
    cout << "Give me some number!\n";
    return 0;
  }
  int number = atoi(argv[1]);
  for(int i = 0; i <= number; i++){
    cout << "Factorial of " << i << " is: " << fact(i) << endl;
  }
  return 0;
}