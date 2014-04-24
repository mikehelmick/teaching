/**   @file addres_book_test.h    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Unit tests for the AddressBook class.
      */
      
#ifndef ADDRESS_BOOK_TEST_H
#define ADDRESS_BOOK_TEST_H

#include <address_book.h>
#include <contact.h>
#include <phone_number.h>

#include <string>

#include <cxxtest/TestSuite.h>

using namespace std;

class AddressBookTest : public CxxTest::TestSuite {
public:
  void testDefaultConstructor() {
    AddressBook book;
    TS_ASSERT_EQUALS(0, book.size());
  }
  
  void testAddContact() {
    string name = "Homer Simpson";
    AddressBook book;
    Contact contact(name);
    TS_ASSERT_EQUALS(0, book.addContact(contact));
    TS_ASSERT_EQUALS(1, book.size());
  }

  void testAddContacts() {
    string name = "Mr. Dr.";
    string number = "123-456-7890";
    AddressBook book;

    // Add 50,000 contacts with 50 phone numbers each
    for (int i = 0; i < 10000; i++) {
      Contact c(name);
      for (int j = 0; j < 50; j++) {
        PhoneNumber pn(PT_WORK, number);
        c.addPhoneNumber(pn);
      }
      TS_ASSERT_EQUALS(i, book.addContact(c));
      TS_ASSERT_EQUALS(i + 1, book.size());
      TS_ASSERT_EQUALS(50, book.getContact(i)->getPhoneNumbers()->size());
    }
  }
};

#endif
