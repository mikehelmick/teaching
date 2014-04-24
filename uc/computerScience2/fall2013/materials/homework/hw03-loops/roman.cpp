/**   @file roman.cpp    
      @author Paul Talaga     // Change me!
      @date 09-15-2013        // Change me!
      @version 0.01   
      
      This program converts positive integers into roman numerals and strings
      representing roman numerals back to numbers.
      
      */

#include <iostream>
#include <string>

using namespace std;

unsigned long charToValue(string c){
  if(c == "I"){
    return 1;
  }else if(c == "V"){
    return 5;
  }else if(c == "X"){
    return 10;
  }else if(c == "L"){
    return 50;
  }else if(c == "C"){
    return 100;
  }else if(c == "D"){
    return 500;
  }else if(c == "M"){
    return 1000;
  }else{
    return 0;
  }
}

/**
  * Converts a string of roman numerals into s unsigned long int.
  * @param roman - String of roman numerals.
  * @return - The numerals converted to an unsigned long.
  */
unsigned long romanToLong(string roman){
  if(roman.size() == 0){
    return 0;
  }
  if(roman.size() == 1){
    return charToValue(roman);
  }
  unsigned int ret = 0;
  unsigned int last = romanToLong(roman.substr(0,1));
  for(int i = 0; i < roman.size(); i++){
    unsigned int val = romanToLong(roman.substr(i,1));
    ret = ret + val;
    if(val > last){ // Need to back up and subtract
      int j = i-1;  // This should be safe 
      while(j >=0 && romanToLong(roman.substr(j,1)) == last){
        ret = ret - 2 * romanToLong(roman.substr(j,1));
        j--;
      }
    }
    last = val;
  }
  return ret;
}

string romanBlock(int value, unsigned long &sum, string str){
  string ret = "";
  while(sum >= value){
    ret += str;
    sum -= value;
  }
  return ret;
}

/**
  * Converts an unsigned long integer to a string, representing
  * the number in Roman Numerals.
  * @param value - The number to convert.
  * @return - A string representing the value.
  */
string longToRoman(unsigned long value){
  string ret = romanBlock(1000, value, "M");
  ret += romanBlock(900, value, "CM");
  ret += romanBlock(500, value, "D");
  ret += romanBlock(400, value, "CD");
  ret += romanBlock(100, value, "C");
  ret += romanBlock(90, value, "XC");
  ret += romanBlock(50, value, "L");
  ret += romanBlock(40, value, "XL");
  ret += romanBlock(10, value, "X");
  ret += romanBlock(9, value, "IX");
  ret += romanBlock(5, value, "V");
  ret += romanBlock(4, value, "IV");
  ret += romanBlock(1, value, "I");
  return ret;
}

int main(){

  bool loop = true;
  string direction;
  do{
    cout << "Type (R) to convert to roman numerals from an integer,\n";
    cout << "  or (N) to convert a number to roman numerals,\n";
    cout << "  or (Q) to quit.\n:";
    cin >> direction;
    if(direction == "R"){ // numerals to integer
      cout << "Enter capitol roman numerals: ";
      string roman;
      cin >> roman;
      cout << endl << roman << " is " << romanToLong(roman) << endl << endl;
    
    }else if(direction == "N"){ // integer to roman numerals
      cout << "Enter integer to convert: ";
      unsigned long input;
      cin >> input;
      cout << endl << input << " is " << longToRoman(input) << endl << endl;
    }else if(direction == "Q"){
      loop = false;
    }
  
  }while(loop);
  return 0;
}
