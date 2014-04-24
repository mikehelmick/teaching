/**   @file phone_number_test.h    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Contains unit tests for the phone number class.
      */
      
#ifndef PHONE_NUMBER_TEST_H
#define PHONE_NUMBER_TEST_H

#include <phone_type.h>
#include <phone_number.h>

#include <string>

#include <cxxtest/TestSuite.h>

using namespace std;

class PhoneNumbreTest : public CxxTest::TestSuite {
public:
  void testCustomLabel() {
    string label = "Pay Phone";
    string digits = "513-347-1111";
    PhoneNumber number(label, digits);
    TS_ASSERT_EQUALS(PT_CUSTOM, number.getType());
    TS_ASSERT_EQUALS(label, number.getLabel());
    TS_ASSERT_EQUALS(digits, number.getDigits());
  }

  void testStandardTabel() {
    string digits = "800-800-8000";
    PhoneNumber number(PT_HOME, digits);
    TS_ASSERT_EQUALS(PT_HOME, number.getType());
    TS_ASSERT_EQUALS("home", number.getLabel());
    TS_ASSERT_EQUALS(digits, number.getDigits());
  }
};

#endif
