#include <iostream>

using namespace std;

main(){
  int a = 5;
  
  int* b = NULL;
  b = &a;
  
  (*b)++;
  
  cout << "a:" << a << " (" << &a << ")" << endl;
  cout << "b:" << *b << " (" << b << ")" << endl << endl;;
  
  b = new int;
  *b = 99;
  cout << "a:" << a << " (" << &a << ")" << endl;
  cout << "b:" << *b << " (" << b << ")" << endl;
  
  delete b;
  
  // Arrays
  
  int c[10];
  
  for(int i = 0; i < 10; i++){
    c[i] = i;
  }
  
  cout << "c: ";
  for(int i = 0; i < 10; i++){
    cout << c[i] << " ";
  }
  cout << endl<<endl;
  //return 0;
  b = c;
  int* temp = NULL;
  for(int i = 0; i < 10; i++){
    temp = b + i;  
    cout << i << " temp:" << *temp << " (" << temp <<  ")" << endl;
  }
}