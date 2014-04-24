/*
 * pointer.cpp
 * Paul Talaga
 * Pointer demo done on Sept 18, 2013
 */

#include <iostream>

using namespace std;

// Pass by reference
void addOne(int &a){
  a++;
  cout << "One\n";
}

// Pass a pointer
void addOne(int* a){
  (*a)++;
  cout << "Two\n";
}

main(){
  // Pointer to integer
  int a;
  int* b;
  b = &a;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;   // Prints the value of the pointer, the address of a
  cout << "*b:" << *b << endl;  // Prints what b points to, dereferences b.

  a++;
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;   // Prints the value of the pointer, the address of a
  cout << "*b:"<< *b << endl;   // Prints what b points to, dereferences b.     

  // now increment a using b
  (*b)++; // increment whatever b points to, in this case a
          // () are extreemly important, otherwise it will increment b, then dereference

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;   // Prints the value of the pointer, the address of a
  cout << "*b:"<< *b << endl;   // Prints what b points to, dereferences b.                      
  cout << endl;

  // Dynamic memory
  int* dynam = new int;      // As for enough space in the heap to store an integer
                             // and store that memory address in dynam
  *dynam = 99;               // Set whatever dynam points to equal to 99

  cout << "dynam: " << *dynam << "( " << dynam << ")\n";
                             // Note the address of dynam is vastly different than b above
  delete dynam;              // Return the memory dynam points to back to the OS

  cout << "dynam: " << *dynam << "( " << dynam << ")\n"; // DANGER DANGER!!!!!!
                             // YOU SHOULD NEVER ACCESS MEMORY AFTER YOU DELETED IT!
                             // Sadly C++ won't prevent us from doing this.
                             // Note that delete doesn't change dynam (the address) at all
                             // You should set a pointer to NULL after a delete for safety
  dynam = NULL;              // NULL is guaranteed to not be a valid pointer location

  //  cout << "dynam: " << *dynam << "( " << dynam << ")\n"; // This will fail since dynam is now NULL (0)
  cout << endl;
  // Arrays!

  int ar[5]; // Define an array of 5 integers
             // Note the bad use of magic numbers!

  // Fill the array with 5+ it's index [6,7,8,9,10]
  for(int i = 0; i < 5; i++){
    ar[i] = i+5;
  }

  b = ar;    // b is an int*    This shows that ar is actually an int* as well.

  cout << "b[]: ";
  for(int i = 0; i < 5; i++){
    cout << b[i] << " ";   // What? b is a pointer, not an array, this should be possible!
  }                        // Thus b[i] really is *(b + i), it just does pointer math!
  cout << endl;            // This explains why you can put any number in for i and get a segmentation
                           // fault.

  cout << "b+i: ";
  for(int i = 0; i < 5; i++){
    cout << *(b+i) << " "; // Same thing!
  }
  cout << endl << endl;;

  // C strings
  //     Strings in C are really just arrays of characters

  char* str1 = "hello";
  char str2[] = "hello2";    // Same thing!

  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << endl;
  // These two char arrays print fine because cout knows that to print a char* it needs to print each
  // character until it sees a null character (0), then it stops.

  str1 = "This is a long string";
  cout << "str1: " << str1 << endl;
  // Now lets loop through each character and print them out
  for(int i = 0; i < 22; i++){
    cout << "i: " << i << " chr: " << str1[i] << " int: " << (int)str1[i] << endl; 
  }
  // Look! Ascii!
  return 0;
}
