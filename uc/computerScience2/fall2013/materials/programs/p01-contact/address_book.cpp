/**   @file address_book.cpp    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Contains the implemtnation for the AddressBook class, see
      address_book.h for the interface defintion.
      */

#include <address_book.h>


AddressBook::AddressBook() {
  contacts = new vector<Contact*>();
}

AddressBook::~AddressBook() {
  for (vector<Contact*>::iterator it = contacts->begin(); it != contacts->end(); it++) {
    delete (*it);
  }
  delete contacts;
}

int AddressBook::addContact(const Contact& newContact) {
  contacts->push_back(new Contact(newContact));
  return contacts->size() - 1;
}

const Contact* AddressBook::getContact(int i) const {
  return contacts->at(i);
}

int AddressBook::size() const {
  return contacts->size();
}
