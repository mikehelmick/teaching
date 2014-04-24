/**   @file main.cpp    
      @author Paul Talaga     // Change me!
      @date 09-11-2013        // Change me!
      @version 0.01   
      
      This file demonstrates the use of the BigInt class by finding the Fibonacci numbers that
			would otherwise overflow any built-in integer representation.
      
      */

#include <iostream>
#include <string>
#include "bigint.h"

using namespace std;

BigInt fib(int n){
	if(n == 0){
		return BigInt(0);
	}
	if(n == 1){
		return BigInt(1);
	}
	BigInt b2 = BigInt(0);
	BigInt b1 = BigInt(1);
	for(int i = 0; i < n; i++){
		BigInt next(b2);
		next.add(b1);
		b2 = b1;
		b1 = next;
	}
	return b2;
}

int main(int argc, char* argv[]){
  if(argc != 2){
  	cout << "Enter fib value to find\n\n";
		return 1;
  }
	int n = atoi(argv[1]);
	BigInt result = fib(n);
	cout << "f(" << n << ")=" << result.getAsDigits() << endl << endl;
  return 0;
}
