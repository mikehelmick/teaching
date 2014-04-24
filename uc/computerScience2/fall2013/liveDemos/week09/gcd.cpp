/*
 * gcd.cpp
 * Paul Talaga
 * 
 * Given 2 numbers, returns the greatest common divisor between them.
 *
 * Oct 22 ,2013
 */

#include <iostream>

using namespace std;

int gcd(int a, int b){    // Implements Euclid's formula (verbatim)
  if(b == 0){
    return a;
  }
  return gcd(b, a % b);   
}

int main(int argc, char* argv[]){
  if(argc <= 2){
    cout << "Give me 2 numbers!\n";
    return 0;
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  cout << "GCD of " << a << " and " << b << " is: " << gcd(a,b) << endl;
  return 0;
}