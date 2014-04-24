/**   @file helloworld-solution.cpp    
      @author Paul Talaga 
      @date 08-28-2013  
      @version 0.01   */

#include <iostream>
#include <string>

using namespace std;

int main(){
  string name;
  string task;
  
  cout << "Hi! What is your name?" << endl;
  getline(cin, name);
  cout << "Hi " << name << ", it's nice to meet you." << endl;
  cout << "What would you like me to do?" << endl;
  getline(cin, task);
  cout << "Oh " << name << ", doing " << task << " seems pointless.\n";
  cout << "Sorry, I can't help you.\n\nBye!\n";
  
  return 0;
}