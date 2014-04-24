/*
 * charcount.cpp
 * Paul Talaga
 * Input/output demo done on Sept 30, 2013
 * Reads in wordswithfriends.txt and prints out the percentages of each character.
 *
 */
 
#include <fstream>
#include <iostream>

using namespace std;

int main(){
  ifstream foo;
  
  foo.open("wordswithfriends.txt");

  int i = 0;
  int counts[26];
  
  // initialize the array with all 0's
  for(int i = 0; i < 26; i++){
    counts[i] = 0;
  }

  char ch;
  //while(foo >> ch){
  while(foo.fail()){
    foo >> ch;
    //cout << i << ": " << word << '-' << static_cast<int>(word) << endl;
    int num = static_cast<int>(ch); // get it as an integer
    if(num >= 'a' && num <= 'z'){ // 'a' is really an int, so make sure we have a
      num = num - 'a';            // lower case letter.  Get num 0-based
      counts[num]++;              // Increment that spot in the array
    }else{
      cout << "Got garbage! " << ch << endl;  
    }
    i++;
  }
  
  foo.close();  // close the file
  
  // print out the stats
  for(int j = 0; j < 26; j++){
    cout << static_cast<char>(j+'a') << ":" << (counts[j] * 100) / i << " %\n";
  }
}