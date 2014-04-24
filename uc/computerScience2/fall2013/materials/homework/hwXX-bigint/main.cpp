/**   @file main.cpp    
      @author Paul Talaga     // Change me!
      @date 09-11-2013        // Change me!
      @version 0.01   
      
      This file demonstrates the use of the BigInt class.
      
      */

#include <iostream>
#include <string>
#include "bigint.h"

using namespace std;

int main(){
  // Make an BigInt that isn't initialized.
 /* BigInt a;
  cout << 0 << ": "<< a.getAsDigits() << endl;  // Should be 0
  a.add(5);
  cout << 5 << ": " << a.getAsDigits() << endl;  // Should be 5
  
  a.multiply(BigInt(50));
  cout << 250 << ": " << a.getAsDigits() << endl;  // Should be 250
  
  a.multiply(BigInt(71));
  cout << 17750 << ": " << a.getAsDigits() << endl;  // Should be 17750
  
  a.multiply(35712);
  cout << 633888000 << ": " << a.getAsDigits() << endl;  // Should be 633888000

  BigInt b = BigInt(71);
  
  a.add(b);
  cout << 633888071 << ": " << a.getAsDigits() << endl;  // Should be 633888071
  
  a.add(b);
  cout << 633888142 << ": " << a.getAsDigits() << endl;  // Should be 633888142
  
  cout << 71 << ": " << b.getAsDigits() << endl;  // Should be 71
  
  b.add(BigInt(-75));
  cout << b.getAsDigits() << endl;
  return 0;
  //a.divide(b);
  */
  BigInt a = BigInt(1234);
    a.subtract(BigInt(111235));
  
  cout << a.getAsDigits() << endl;

  
  
  return 0;
}
