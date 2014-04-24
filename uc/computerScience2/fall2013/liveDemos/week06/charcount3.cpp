/*
 * charcount3.cpp
 * Paul Talaga
 * Input/output demo done on Oct 1, 2013
 * If no arguments are given, this program takes input from stdin, otherwise it
 * opens and reads the filename given.
 *
 */
 
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

  string filename;
  istream* foo;
  ifstream file;
  
  if(argc == 2){
    filename = argv[1];
    file.open(filename.c_str());
    if(file.fail()){
      cout << "Error opening " << filename << endl;
      return 0;
    }
    cout << "Reading from: " << filename << endl;
    foo = static_cast<istream *>(&file);
  }else if(argc == 1){
    foo = static_cast<istream *>(&cin);
  }

  int i = 0;
  int counts[26];
  
  // initialize the array with all 0's
  for(int i = 0; i < 26; i++){
    counts[i] = 0;
  }

  char ch;
  while(*foo >> ch){
    int num = static_cast<int>(ch); // get it as an integer
    if(num >= 'a' && num <= 'z'){ // 'a' is really an int, so make sure we have a
      num = num - 'a';            // lower case letter.  Get num 0-based
      counts[num]++;              // Increment that spot in the array
      i++;
    }else{
      cout << "Got garbage! " << ch << endl;  
    }
    
  }
  
  if(argc == 2){
    file.close();  // close the file
  }
  
  // print out the stats
  for(int j = 0; j < 26; j++){
    cout << static_cast<char>(j+'a') << ":" << (counts[j] * 100) / i << " %\n";
  }
}