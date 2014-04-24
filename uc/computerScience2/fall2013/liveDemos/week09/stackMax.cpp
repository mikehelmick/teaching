/*
 * stackMax.cpp
 * Paul Talaga
 * 
 * Code to see how many times we can recurse.
 * This will segfault (without compiler optimizations) when we break out of the stack.
 * Oct 21 , 2013
 */
 
#include <iostream>
#include <cstdlib>

using namespace std;

long infinite(long num){
  int a[10];              // By adding internal variables we increase the size of a stack
  cout << num << endl;    // frame, and thus how many times we can recurse.
  return infinite(num+1); // Prints out the number of times it is called.
}

int main(){
  infinite(1);
  return 0;
}