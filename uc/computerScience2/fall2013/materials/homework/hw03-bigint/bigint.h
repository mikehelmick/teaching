#ifndef BIGINT_H
#define BIGINT_H  

/**   @file bigint.h    
      @author Paul Talaga     // Change me!
      @date 09-11-2013        // Change me!
      @version 0.01   
      
      This BigInt class implements an infinitely long non-negative integer, with some 
      mathematical operations possible:  addition, subtraction, multiplication, 
      and division.
      
      BitInts can be initialized via a long, a string of digits, or a string 
      of binary digits (0bxxxx).
      
      BigInts can be retrieved as a string of digits, or as a string of binary
      digits.
      
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
    * Creates a new BigInt from a long integer
    */
  BigInt(long number);
  
  /**
    * Creates a new BigInt from a string of digits.
    * Or, if the string starts with 0b, then interpret as binary
    */
  BigInt(string number);
  
  /**
    * Create a new BigInt from another one.
    */
  BigInt(const BigInt& number);
  
  /**
    * Return true if the sent BigInt has the same value.
    */
  bool isEqual(BigInt number);
  
  /**
    * Return true if 'this' < number
    */
  bool isLess(BigInt number);
  
  /**
    * Return true if 'this' > number
    */
  bool isGreater(BigInt number);
  
  /**
    * Return the Bigint as a string of digits or binary (0bxxxx)
    * With negative binary (0-bxxxx)
    */
  string getAsDigits();
  string getAsBinary();
  /**
    * Return the Bigint as a long.  Returns maxlong (minlong) if BigInt larger than
    * long supports.
    */
  long getAsLong();
  
  /**
    * Adds/subtract another Bigint to the current one and changes 'this' object.
    * ('this' - number) for subtraction
    * If subtraction would result in a negative value, set equal to 0.
    */
  void add(BigInt number);
  void subtract(BigInt number);
  
    /**
    * Multiply/divide another Bigint (rr long) to the current one and 
    * changes 'this' object.
    * ('this' / number) for division
    */  
  void multiply(BigInt number);
  void multiply(long number);
  void divide(BigInt number);
  
  void compactBlocks();
  
  private:

  
  /**
    * Multiply/divide the number by mult x MAX_NUM_PER_BLOCKs
    */
  void multBlock(unsigned int mult);
  void divBlock(unsigned int mult);
  
  /**
    * Remove zero blocks on large end
    */
  //void compactBlocks();
  
  /**
    * Negate blocks, used for subraction
    */
   void negateBlocks();
   bool nonNegBlocks();
   bool isLessBlocks(BigInt number);
  
  vector<long> number_blocks;
  
  bool isNegative;
  
};
  
#endif  
