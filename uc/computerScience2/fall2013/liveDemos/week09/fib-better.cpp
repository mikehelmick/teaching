/*
 * fib-better.cpp
 * Paul Talaga
 * 
 * A better recursive version of a recursive fibonacci.
 * O(n)
 * Oct 21 , 2013
 */
 
#include <iostream>

using namespace std;

/*  fibBack will pass the last 2 values of the fibonacci sequence 'up' to the next version.
 *  Thus this function starts at the bottom and goes up, rather than down.
 */
unsigned long fibBack(int dest, int location, unsigned long n2, unsigned long n1){
  if(dest <= location){ // Base case is when  we've reached our destination
    return n1+n2;
  }
  return fibBack(dest, location + 1, n1, n1 + n2);
}

unsigned long fib(int num){
  // Since we need to pass more than 1 piece of information to the recursive call, we
  // create a recursive helper function.  If in a class, this would be public and the
  // recursive helper would be private.
  return fibBack(num, 2, 0, 1); // Start at the bottom with the correct starting sequence
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