/**   @file phone_number.h    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Contains the interface for the PhoneNumber
      */

#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <phone_type.h>

#include <string>

using namespace std;

class PhoneNumber {
public:
  PhoneNumber(const string &customLabel, const string &digits);
  PhoneNumber(PhoneType type, const string &digits);

  PhoneNumber(const PhoneNumber& other);

  virtual ~PhoneNumber();
  
  PhoneType getType() const;
  string getLabel() const;

  string getDigits() const;

private:
  PhoneType type;
  string customLabel;
  string digits;
};

#endif