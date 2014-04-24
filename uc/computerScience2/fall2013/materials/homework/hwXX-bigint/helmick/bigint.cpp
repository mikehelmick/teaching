#include "bigint.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <climits>

BigInt::BigInt() : negative(false) {
  digits.push_back(0);
}

BigInt::BigInt(long number) {
  string asString = longToString(number);
  init(asString);
}

BigInt::BigInt(string number) {
  init(number);
}

BigInt::BigInt(const BigInt& number) :
    negative(number.negative),
    digits(number.digits) {
}

void BigInt::init(string& number) {
  negative = false;
  for(string::reverse_iterator rit = number.rbegin(); rit != number.rend(); rit++) {
    char digitChar = *rit;
    if (digitChar == '-' && rit + 1 == number.rend()) {
      negative = true;
    } else {
      int digit = charToDigit(digitChar);
      digits.push_back(digit);
    }
  }
}

string BigInt::longToString(long number) {
  stringstream strstream;
  strstream << number;
  return strstream.str();
}

int BigInt::charToDigit(char charDigit) {
  if (charDigit < '0' || charDigit > '9') {
    stringstream message;
    message << "Invalid character in input '" << charDigit << "', cannot interpret as digit";
    throw invalid_argument(message.str());
  }
  return charDigit - '0';
}

int BigInt::compareTo(const BigInt &that) {
  // If one is negative and 
  if (negative && !that.negative) {
    return -1;
  } else if (!negative && that.negative) {
    return 1;
  }

  // At this point the sign is the same.
  int magnitudeComp = vectorCompareAbs(digits, that.digits);
  // If you get to the end and magnitudeComp is still 0, the values are equal;
  
  if (negative) {
    return magnitudeComp * -1;
  } else {
    return magnitudeComp;
  }
}

int BigInt::signedVectorCompare(const bool lhsNegative, const vector<int> &lhs,
    const bool rhsNegative, const vector<int> &rhs) {
      
}

int BigInt::vectorCompareAbs(const vector<int> &lhs, const vector<int> &rhs) {
  int magnitudeComp = lhs.size() - rhs.size();
  if (magnitudeComp == 0 && lhs.size() != 0) {
    // Actually have to peek at the value. Start from the end, move forward
    int lhsIdx = lhs.size() - 1;
    int rhsIdx = rhs.size() - 1;
    while (magnitudeComp == 0 && lhsIdx >= 0) {
      magnitudeComp = lhs[lhsIdx] - rhs[rhsIdx];
      lhsIdx--;
      rhsIdx--;
    }  
  }
  return magnitudeComp;
}

bool BigInt::isEqual(const BigInt& number) {
  return this->compareTo(number) == 0;
}

bool BigInt::isLess(const BigInt& number) {
  return this->compareTo(number) < 0;
}

bool BigInt::isGreater(const BigInt& number) {
  return this->compareTo(number) > 0;
}

string BigInt::getAsDigits() {
  stringstream asDigits;
  if (negative) {
    asDigits << '-';
  }
  for (vector<int>::reverse_iterator rit = digits.rbegin(); rit != digits.rend(); rit++) {
    asDigits << *rit;
  }
  return asDigits.str();
}

string BigInt::getAsBinary() {
  return "";
}

long BigInt::getAsLong() {
  return 0;
}

void BigInt::output(string name, const vector<int> &data) {
  cout << name << " = ";
  for (unsigned int i = 0; i < data.size(); i++) {
    cout << data[i];
  }
  cout << endl;
}

void BigInt::add(const BigInt& number) {    
  // if the signs are the same, addition and preserve sign
  if (negative == number.negative) {
    vectorAdd(digits, number.digits);
  } else {
    // signs are different, subtract the smaller from the larger
    // preserve the sign of the larger magnitude number
    vectorSubtract(negative, digits, number.negative, number.digits);
  }
}

void BigInt::vectorAdd(vector<int> &lhs, const vector<int> &rhs) {
  // Make a copy of the rhs  data, so we don't mess with it
  unsigned int idx = 0;
  vector<int> b(rhs);
  // get vectors to same length by zero padding;
  while (lhs.size() < b.size()) {
    lhs.push_back(0);
  }
  while (b.size() < lhs.size()) {
    b.push_back(0);
  }
  
  int carry = 0;
  while (idx < lhs.size()) {
    int result = lhs[idx] + b[idx] + carry;
    adjustResultAndCarry(result, carry);
    lhs[idx] = result;
    idx++;
  }
  if (carry != 0) {
    lhs.push_back(carry);
  }
}

/**
 * 
 */
void BigInt::vectorSubtract(bool &lhsNegative, vector<int> &lhs,
    const bool &rhsNegative, const vector<int> &rhs) {
  vector<int> larger(lhs);
  vector<int> smaller(rhs);
  if 
}

void BigInt::adjustResultAndCarry(int &result, int &carry) {
  if (result < 10) {
    carry = 0;
  } else {
    carry = 1;
    result = result - 10;
  }
}

void BigInt::subtract(const BigInt& number) {
  
}

void BigInt::multiply(const BigInt& number) {
  
}

void BigInt::multiply(long number) {
  BigInt b(number);
  multiply(b);
}

void BigInt::divide(const BigInt& number) {
  
}
