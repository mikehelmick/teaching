#ifndef BIGINT_H
#define BIGINT_H  

/**   @file bigint.h    
      @author Paul Talaga     // Change me!
      @date 11-23-2013        // Change me!
      @version 0.01   
      
      This BigInt class implements an infinitely long non-negative integer, with 3 
      mathematical operations possible:  addition, subtraction, and equality comparison.
      
      BitInts can be initialized via a long, or a string of digits (ascii).
      
      BigInts can be retrieved as a string of digits or converted to an unsigned long.
      
      */

#include <string>
#include <vector>

using namespace std;

/**
  * Class representing a integer class capable of very large non-negative numbers.
*/
class BigInt{

public:
  
  /**
    * Default constructor initializes to 0
    */
  BigInt();
  
  /**
    * Creates a new BigInt from an unsigned long integer
    */
  BigInt(const unsigned long& number);
  
  /**
    * Creates a new BigInt from a string of ascii digits.  Throws exception if value is negative.
	  * Only needs to handle digits representing an integer, nothing larger.
    */
  BigInt(const string& number);
  
  /**
    * Create a new BigInt from another one. (Copy Constructor)
    */
  BigInt(const BigInt& number);
	
	/**
	 * Destructor 
	 */
	~BigInt();
  
  /**
    * Return true if the sent BigInt has the same value as 'this'.
    */
  bool isEqual(const BigInt& number);
  
  /**
    * Return the Bigint as a string of digits.
	  * Extra leading 0's is OK.
    */
  string getAsDigits();
 
  /**
    * Return the Bigint as an unsigned long.  Causes an exception if BigInt is larger than unsigned
    * long supports.
    */
  unsigned long getAsLong();
  
  /**
    * Adds/subtract another Bigint to the current one and changes 'this' object.
    * ('this' - number) for subtraction
    * If subtraction would result in a negative value, throw an exception.
    */
  void add(const BigInt& number);
  void subtract(const BigInt& number);
  
  private:
		
	// FILL ME IN IF NEEDED
  
};
  
#endif  
