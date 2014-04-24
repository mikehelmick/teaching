#ifndef BIGINT_H
#define BIGINT_H  

/**   @file bigint.h    
      @author Mike Helmick
      @date 9/15/2013
      */

#include <string>
#include <vector>

using namespace std;

/**
  * Class representing a integer class capable of very large signed numbers.
  This BigInt class implements an infinitely long non-negative integer, with some 
  mathematical operations possible:  addition, subtraction, multiplication, 
  and division.
  
  BitInts can be initialized via a long, a string of digits, or a string 
  of binary digits (0bxxxx).
  
  BigInts can be retrieved as a string of digits, or as a string of binary
  digits.
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

  /*
   * @Return neg if this is less than that, zero if equal and 1 if this is greater than that.
   */
  int compareTo(const BigInt &that);
  
  /**
    * Return true if the sent BigInt has the same value.
    */
  bool isEqual(const BigInt &number);
  
  /**
    * Return true if 'this' < number
    */
  bool isLess(const BigInt &number);
  
  /**
    * Return true if 'this' > number
    */
  bool isGreater(const BigInt &number);
  
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
  void add(const BigInt &number);
  void subtract(const BigInt &number);
  
    /**
    * Multiply/divide another Bigint (rr long) to the current one and 
    * changes 'this' object.
    * ('this' / number) for division
    */  
  void multiply(const BigInt &number);
  void multiply(long number);
  void divide(const BigInt &number);
  
private:
  bool negative;
  // Each digit as base 10, least significant first.
  vector<int> digits;

  void init(string& number);
  string longToString(long number);
  int charToDigit(char charDigit);

  void adjustResultAndCarry(int &result, int &carry);

  int signedVectorCompare(bool lhsNegative, const vector<int> &lhs,
    bool rhsNegative, const vector<int> &rhs);
  int vectorCompareAbs(const vector<int> &lhs, const vector<int> &rhs);
  void vectorAdd(vector<int> &lhs, const vector<int> &rhs);
  void vectorSubtract(bool &lhsNegative, vector<int> &lhs,
      const bool &rhsNegative, const vector<int> &rhs);
      
  // debugging assistance
  void output(string name, const vector<int> &data);
};
  
#endif  
