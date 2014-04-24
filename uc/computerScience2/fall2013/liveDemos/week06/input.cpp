/*
 * input.cpp
 * Paul Talaga
 * Input/output demo done on Sept 30, 2013
 */
 
#include <fstream>
#include <iostream>

using namespace std;

int main(){
  ifstream foo;
  ofstream bar;
  
  foo.open("data1.txt");
  bar.open("output1.txt");

  int i = 0;

  int number;
  while(foo >> number){
    bar << i << ": " << number << endl;
    i++;
  }
  
  foo.close();
  bar.close();
}