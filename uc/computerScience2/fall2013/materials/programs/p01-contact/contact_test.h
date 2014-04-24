/**   @file contact_test.h    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Contains unit tests for the Contact class.
      */
      
#ifndef CONTACT_TEST_H
#define CONTACT_TEST_H

#include <phone_number.h>
#include <contact.h>

#include <string>

#include <cxxtest/TestSuite.h>

using namespace std;

class ContactTest : public CxxTest::TestSuite {
public:
  void testConstructor() {
    string name = "Bart Simpson";
    Contact c(name);
    TS_ASSERT_EQUALS(name, c.getName());
    TS_ASSERT_EQUALS(0, c.getPhoneNumbers()->size());
  }

  void testAddPhoneNumber() {
    string name = "Bart Simpson";
    Contact c(name);
    PhoneNumber pn("Mobile Phone", "123-456-7890");
    c.addPhoneNumber(pn);
    TS_ASSERT_EQUALS(name, c.getName());
    TS_ASSERT_EQUALS(1, c.getPhoneNumbers()->size());
    TS_ASSERT_EQUALS(PT_CUSTOM, c.getPhoneNumbers()->at(0)->getType());
    TS_ASSERT_EQUALS("Mobile Phone", c.getPhoneNumbers()->at(0)->getLabel());
    TS_ASSERT_EQUALS("123-456-7890", c.getPhoneNumbers()->at(0)->getDigits());
  }

  void testAddABunchOfPhoneNumbers() {
    string name = "Stephen Colbert";
    string number = "347-1111";
    Contact c(name);
    // 1,000,000 is overkill, just showing what can be done here.
    for (int i = 0; i < 1000000; i++) {
      PhoneNumber pn(PT_HOME, number);
      c.addPhoneNumber(pn);
      TS_ASSERT_EQUALS(i + 1, c.getPhoneNumbers()->size());
      TS_ASSERT_EQUALS(PT_HOME, c.getPhoneNumbers()->at(i)->getType());
      TS_ASSERT_EQUALS(number, c.getPhoneNumbers()->at(i)->getDigits());
    }
    // Retest another value
    TS_ASSERT_EQUALS(PT_HOME, c.getPhoneNumbers()->at(400)->getType());
    TS_ASSERT_EQUALS(number, c.getPhoneNumbers()->at(400)->getDigits());
  }
};

#endif
