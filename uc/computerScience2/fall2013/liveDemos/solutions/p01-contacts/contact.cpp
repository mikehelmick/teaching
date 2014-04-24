/**   @file contact.cpp    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Contains the implemntation for the Contact class, see
      contact.h for the interface.
      */

#include <contact.h>

Contact::Contact(const string& name) : name(name) {
  // vector is auto initialized
  phoneNumbers = new vector<PhoneNumber*>();
}

Contact::Contact(const Contact& other) {
  phoneNumbers = new vector<PhoneNumber*>();
  for (unsigned int i = 0; i < other.phoneNumbers->size(); i++) {
    // Make a copy of the individual phone numbers, to avoid dealing with shared pointers.
    phoneNumbers->push_back(new PhoneNumber(*(other.phoneNumbers->at(i))));
  }
}

Contact::Contact() {
  // private / unsed
}

Contact::~Contact() {
  // Clean up the individual phone numbers
  for (unsigned int i = 0; i < phoneNumbers->size(); i++) {
    delete phoneNumbers->at(i);
  }
  // then clean up the container
  delete phoneNumbers;
}

string Contact::getName() const {
  return name;
}

const vector<PhoneNumber*>* Contact::getPhoneNumbers() const {
  return phoneNumbers;
}

void Contact::addPhoneNumber(const PhoneNumber &phoneNumber) {
  phoneNumbers->push_back(new PhoneNumber(phoneNumber));
}
