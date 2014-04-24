/**   @file math-series.cpp    
      @author Paul Talaga 
      @date 08-25-2013  
      @version 0.01   */
      
/*
  This program estimates sin and cos using a series estimator.
  x! = x * (x-1) * (x-2) * ... 1
  sin(x) = x - x^3/3! + x^5/5! - x^7/7! ...
  cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! ...
  
  Consider renaming sin and cos in this file
*/

#include <iostream>
#include <cmath>  // For pow, but also to check sin() and cos()

using namespace std;

/*
  Implements the factorial function.
  @param x (unsigned int): The input 
  @return Returns the factorial of x */
unsigned long factorial(unsigned long x){
  unsigned long ret = 1;
  for( ; x >=1; x--){ // not obvious, in demo use counter 
    ret = ret * x;
  }
  return ret;
}

/*
  Implements a series estimation of sin.
  sin(x) = x - x^3/3! + x^5/5! - x^7/7! ...
  @param x (double): The input in radians
  @param terms (uint): The number of terms to use
  @return Returns the sin of the input. */
double sin(double x, unsigned int num_terms){
  double acc = x; 
    // Start with 2 since first term is set above, 1 based counting
  for(int i = 2; i <= num_terms; i++){  
    double term = pow(x, i * 2 -1) / factorial(i * 2 - 1);
    if(i % 2 == 1){ // if odd, add term
      acc += term;
    }else{  // otherwise subtract
      acc -= term;
    }
  }
  return acc;
}

/*
  Implements a series estimation of cos.
  cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! ...
  @param x (double): The input in radians
  @param terms (uint): The number of terms to use
  @return Returns the cos of the input. */
double cos(double x, unsigned int num_terms){
  double acc = 1.0; 
    // Start with 2 since first term is set above, 1 based counting
  for(int i = 2; i <= num_terms; i++){ // count from 1
    double term = pow(x, i * 2 -2) / factorial(i * 2 - 2);
    if(i % 2 == 1){ // if odd, add term
      acc += term;
    }else{  // otherwise subtract
      acc -= term;
    }
  }
  return acc;
}

int main(int argc, const char* argv[]){
  //cout << pow(5,5);  // Try this and talk about error
  cout << "sin real: " << sin(0.2) << " my: " << sin(0.2,10) << endl;
  cout << "cos real: " << cos(0.2) << " my: " << cos(0.2,10) << endl;
  cout << "Diff comparison:" << endl;
  double error = 1;
  int i = 1;
  // Or write as while loop
  do{
    error = abs(sin(0.5) - sin(0.5,i));
    cout << sin(0.2) << " : " << sin(0.2,10) << " error: " << error << endl;
    i = i + 1; // forget this and talk about logic error
  }while(error > 0.00001);
  
  return 0;
}