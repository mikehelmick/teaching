/**   @file Contact.h    
      @author Mike Helmick    // Change me!
      @date 09-22-2013        // Change me!
      
      Contains the interface for the Contact class. The contact class
      represents a single contact in a digital address book.
      */

#ifndef CONTACT_H
#define CONTACT_H

#include <phone_number.h>

#include <string>
#include <vector>

using namespace std;

/**
 */
class Contact {
public:
  /**
   * Creates a new contact, with no phone numbers stored.
   */
  Contact(const string& name);
  
  /** copy constructor */
  Contact(const Contact& other);

  virtual ~Contact();

  string getName() const;

  /** Returns a pointer to a vector of PhoneNumber pointers.
   * The contact class OWNS this memory, you may not change
   * or delete the contents.
   */
  const vector<PhoneNumber*>* getPhoneNumbers() const;

  /**
   * Adds a new phone number to this contact. A copy is 
   * made, so you are free to do whatever you like after the method call
   */
  void addPhoneNumber(const PhoneNumber &phoneNumber);

private:
  Contact();

  string name;
  vector<PhoneNumber*>* phoneNumbers; 
};

#endif