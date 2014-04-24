/**   @file helloworld.cpp    
      @author Paul Talaga     // Change me!
      @date 08-28-2013        // Change me!
      @version 0.01   */

#include <iostream>
#include <string>

using namespace std;


int main(int argc, const char* argv[]){
  string name;
  
  cout << "Hi! What is your name?" << endl;
  getline(cin, name);
  cout << name << endl;
  
  return 0;
}