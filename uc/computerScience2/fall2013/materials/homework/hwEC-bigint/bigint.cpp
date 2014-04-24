#include "bigint.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <climits> // for ULONG_MAX

#include <iostream>

const unsigned long MAX_NUM_PER_BLOCK = 1000;

BigInt::BigInt(){
  // least significant part on left (0) side
  //number_blocks.push_back(0);
}

BigInt::BigInt(const unsigned long &mynumber){
	unsigned long number = mynumber;
  long carry = number / MAX_NUM_PER_BLOCK;
  long rem = number % MAX_NUM_PER_BLOCK;
  number_blocks.push_back(rem);
  number = carry;
  while(carry != 0){
    carry = number / MAX_NUM_PER_BLOCK;
    rem = number % MAX_NUM_PER_BLOCK;
    number_blocks.push_back(rem);
    number = carry;
  }
}

BigInt::BigInt(const BigInt& number){
  number_blocks = number.number_blocks;
}

BigInt::BigInt(const string& snumber){	// FIX ME!
	long number = strtol(snumber.c_str(), NULL, 0);	// 	DOES NOT handle numbers larger than long int!
	if(number < 0){
		throw invalid_argument("Can not handle negative values!");
		return;
	}

  long carry = number / MAX_NUM_PER_BLOCK;
  long rem = number % MAX_NUM_PER_BLOCK;
  number_blocks.push_back(rem);
  number = carry;
  while(carry != 0){
    carry = number / MAX_NUM_PER_BLOCK;
    rem = number % MAX_NUM_PER_BLOCK;
    number_blocks.push_back(rem);
    number = carry;
  }
}

BigInt::~BigInt(){
	// Do nothing since we don't use new
}

string BigInt::getAsDigits(){
  compactBlocks();
  if(number_blocks.size() == 0){
    return "0";
  }
  string ret = "";

  for(unsigned int i = 0; i < number_blocks.size(); i++){
    //cout << i << ":" << number_blocks[i] << " ";
    string temp = "";
    stringstream out;
    int b = number_blocks[i]; // Ugly way to convert int to string
    out << b;
    temp = out.str();
    while(temp.size() < 3 
      && i < number_blocks.size() - 1){ // Don't pad if largest block
      temp = "0" + temp;                // TODO: What if blocksize non multiple of 10?
    }
    ret = temp + ret ;
  }
  //cout << endl;
  return ret;
}


unsigned long BigInt::getAsLong(){
  if( number_blocks.size() == 0){
    return 0; 
  }
	unsigned long ret = 0;
	unsigned long last = 0;	// To check overflow
	unsigned long baseTrack = 1;	// Way to get around the lack of pow for ints
	for(unsigned int i = 0; i < number_blocks.size(); i++){
		ret += number_blocks[i] * baseTrack ;
		baseTrack *= MAX_NUM_PER_BLOCK;
		if(ret < last){
			throw length_error("Number can not be cast to unsigned long due to size");
		}
		last = ret;
	}
  return ret;
}

bool BigInt::isEqual(const BigInt& number){
  // Make sure both are compacted (no 0 blocks on significant end
  for(unsigned int i = 0; i < number_blocks.size() || i < number.number_blocks.size(); i++){  // Blocks should match
		unsigned long t1 = 0;
		unsigned long t2 = 0;
		if(i < number_blocks.size()){
			t1 = number_blocks[i];
		}
		if(i < number.number_blocks.size()){
			t2 = number.number_blocks[i];
		}
		if(t1 != t2){
			return false;
		}
  }
  return true;  // Must be OK
}



void BigInt::add(const BigInt& number){

  // make a new number, with one more block than the max of the two to handle carry
	// fill with 0's
  BigInt result;
	if(number_blocks.size() > number.number_blocks.size()){
		result.number_blocks = vector<long>(number_blocks.size()+1, 0);
	}else{
		result.number_blocks = vector<long>(number.number_blocks.size()+1, 0);
	}
	
	/*cout << "add ";
	printBlocks();
	number.printBlocks();
	cout << "endadd\n"; */

  
  // add from smallest to largest
	unsigned long carry = 0;
	for(unsigned int i = 0; i < result.number_blocks.size(); i++){
		unsigned long t1 = 0;
		unsigned long t2 = 0;
		if(i < number_blocks.size()){
			t1 = number_blocks[i];
		}
		if(i < number.number_blocks.size()){
			t2 = number.number_blocks[i];
		}
		unsigned long bottom = t1 + t2 + carry;
		if(bottom < t1 || bottom < t2){ // wrap with unsigned long
			cout << "WRAPPING!\n\n";
			throw logic_error("WRAPPING OF ULONG INT NOT IMPLEMENTED");
		}else if(bottom > MAX_NUM_PER_BLOCK){
			result.number_blocks[i] = bottom % MAX_NUM_PER_BLOCK;
			carry = bottom / MAX_NUM_PER_BLOCK;
		}else{
			result.number_blocks[i] = bottom;
			carry = 0;
		}
	}
	//result.printBlocks();
	result.compactBlocks();
	//result.printBlocks();
	number_blocks = result.number_blocks;
	return ;
}

void BigInt::subtract(const BigInt& number){
	// Disallow negatives
	if(isLess(number)){
		throw logic_error("Result of subraction would be negative, not allowed");
	}
	if(isEqual(number)){
		number_blocks = vector<long>();
		return;
	}
	number_blocks.push_back(0); // just so we don't segfault
	// 'this' is larger than number
	// Try to do this inplace.
	for(unsigned int i = 0; i < number_blocks.size(); i++){
		unsigned long t1 = number_blocks[i];
		unsigned long t2 = 0;	// cover the case that number has fewer blocks
		if(i < number.number_blocks.size()){
			t2 = number.number_blocks[i];
		}
		unsigned long bottom =  t1 - t2;
		if(bottom > t1 && bottom > t2){ // Top less than bottom (t1 < t2)
			// Borrow
			number_blocks[i+1]--;				// TODO verify negative resoves itself.
			bottom = MAX_NUM_PER_BLOCK + t1 - t2;
		}
		number_blocks[i] = bottom;
	}
	compactBlocks();	// Remove extra high-order 0 blocks.
  return;
}


void BigInt::compactBlocks(){
  for(int i = (signed int)number_blocks.size() - 1; i >= 0; i--){
    if(number_blocks[i] == 0){
      number_blocks.erase(number_blocks.begin() + i);
    }else{
      return;
    }
  }
}


bool BigInt::isLess(BigInt number){
    return isLessBlocks(number);
}

bool BigInt::isLessBlocks(BigInt number){
  compactBlocks();
  number.compactBlocks();
  // can we measure by block length
  if(number_blocks.size() < number.number_blocks.size()){
    return true;
  }else if(number_blocks.size() > number.number_blocks.size()){
    return false;
  }
  // Must be same length, check actual numbers (all should be positive)
  for(int i = (signed int)number_blocks.size() - 1; i >= 0 ; i--){
    if(number_blocks[i] < number.number_blocks[i]){
      return true;
    }else if(number_blocks[i] > number.number_blocks[i]){
      return false;
    }
  }
  // must be the same!
  return false;
}

void BigInt::printBlocks(){
	for(unsigned int i = 0; i < number_blocks.size(); i++){
		cout << i << ":" << number_blocks[i] << " ";
	}
	cout << endl;
}