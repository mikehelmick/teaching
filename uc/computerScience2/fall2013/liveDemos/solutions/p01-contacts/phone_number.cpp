/**   @file phone_number.cpp    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Contains the implementation for the PhoneNumber class.
      */
      
#include <phone_type.h>
#include <phone_number.h>
#include <string>

using namespace std;

PhoneNumber::PhoneNumber(const string &customLabel, const string &digits)
    : customLabel(customLabel), digits(digits) {
  type = PT_CUSTOM;
}

PhoneNumber::PhoneNumber(PhoneType type, const string &digits)
    : customLabel(""), digits(digits) {
  this->type = type;
}

PhoneNumber::PhoneNumber(const PhoneNumber& other) {
  type = other.type;
  customLabel = other.customLabel;
  digits = other.digits;
}

PhoneNumber::~PhoneNumber() {
  // Nothing to do
}
  
PhoneType PhoneNumber::getType() const {
  return type;
}

// Returns a string for the standard labels, or the custom label.
string PhoneNumber::getLabel() const {
  switch (type) {
    case PT_HOME: return "home";
    case PT_MOBILE: return "mobile";
    case PT_WORK: return "work";
    case PT_FAX: return "fax";
    case PT_CUSTOM:
    default:
      return customLabel;
  }
}

string PhoneNumber::getDigits() const {
  return digits;
}
