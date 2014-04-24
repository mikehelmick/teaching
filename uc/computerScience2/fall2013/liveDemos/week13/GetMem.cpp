#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

struct myStruct {
  long a[100];
};

int main() {
  long bytesUsed = 0;
  long kbUsed = 0;
  long each = sizeof(myStruct);
  long counter = 0;
  
  cout << "Each struct is " << each << " bytes" << endl;
  
  vector<myStruct*>* lePointers = new vector<myStruct*>();

  myStruct* x = NULL;
  for (;;) {
    try {
      x = new myStruct;
    } catch (bad_alloc ex) {
      cout << "Error - no mem could be allocated." << endl;
      
      for (unsigned int i = 0; i < lePointers->size(); i++) {
        delete lePointers->at(i);
      }
      delete lePointers;
      lePointers = new vector<myStruct*>();
    }
    
    bytesUsed += each;
    while (bytesUsed >= 1024) {
      kbUsed++;
      bytesUsed -= 1024;
    }
    counter++;

    if (counter % 10000 == 0) {
      cout << counter << " allocated: " << kbUsed << "kb" << endl;
    }
  }
}