/**   @file address_book.h    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Class definition for the AddressBook class, represents a a digitial address book.
      */

#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <contact.h>

#include <vector>
using namespace std;

class AddressBook {
public:
  AddressBook();
  virtual ~AddressBook();
  
  /**
   * @param newContact the contact to be added
   * @return the index of the new contact
   */
  int addContact(const Contact& newContact);

  /**
   * @param i, the index of the contact to retrieve
   * @return a reference to the contact at that spot
   */
  const Contact* getContact(int i) const;

  int size() const;

private:
  vector<Contact*>* contacts;
};

#endif