/*
 * fib.cpp
 * Paul Talaga
 * 
 * Obvious recursive way to do fibonacci, but not efficient!
 * O(2^n)
 * Oct 21 , 2013
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int fib(int num){
  if(num <= 1){
    return num;
  }
  return fib(num-1) + fib(num-2);   // Note the 2 recursive calls, that is bad for efficiency.
}

int main(int argc, char* argv[]){
  if(argc <= 1){
    cout << "Give me some number!\n";
    return 0;
  }
  int number = atoi(argv[1]);
  for(int i = 0; i <= number; i++){
    cout << "Fibonacci of " << i << " is: " << fib(i) << endl;
  }
  return 0;
}