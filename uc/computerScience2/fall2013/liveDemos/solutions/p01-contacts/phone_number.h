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

/**
 * Class to represent a single phone number.
 * A phone number has a standard label, or  custom label.
 */
class PhoneNumber {
public:
  /** Constructor for a custom label, phone number required */
  PhoneNumber(const string &customLabel, const string &digits);
  /** Constructor for a standard label, phone number required */
  PhoneNumber(PhoneType type, const string &digits);

  /** Copy constructor */
  PhoneNumber(const PhoneNumber& other);

  /** Destructor */
  virtual ~PhoneNumber();
  
  PhoneType getType() const;
  string getLabel() const;

  string getDigits() const;

private:
  // What type
  PhoneType type;
  // Label - Empty string if the type is not PT_CUSTOM
  string customLabel;
  // Gimmie your digits! (email helmick and talaga if you read this line)
  string digits;
};

#endif