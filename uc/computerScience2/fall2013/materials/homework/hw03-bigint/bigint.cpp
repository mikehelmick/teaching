#include "bigint.h"
#include <string>
#include <sstream>
#include <assert.h> // Consider removing

#include <iostream>

const long MAX_NUM_PER_BLOCK = 1000;

BigInt::BigInt(){
  // least significant part on left (0) side
  //number_blocks.push_back(0);
  isNegative = false;
}

BigInt::BigInt(long number){
  if(number < 0){
    number = 0-number;
    isNegative = true;
  }else{
    isNegative = false;
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
  assert(nonNegBlocks());
}

BigInt::BigInt(const BigInt& number){
  number_blocks = number.number_blocks;
  isNegative = number.isNegative;
}

string BigInt::getAsDigits(){
//  assert(nonNegBlocks());
  compactBlocks();
  if(number_blocks.size() == 0){
    return "0";
  }
  string ret = "";
  if(isNegative){
    cout << "negative ";
  }else{
    cout << "positive ";
  }
  for(unsigned int i = 0; i < number_blocks.size(); i++){
    cout << i << ":" << number_blocks[i] << " ";
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
  cout << endl;
  if(isNegative){
    ret = "-" + ret;
  }
  return ret;
}

string BigInt::getAsBinary(){
  return string("Fill me in!");
}

long BigInt::getAsLong(){
  compactBlocks();
  if( number_blocks.size() > 1){
    return MAX_NUM_PER_BLOCK;  // TODO: What to do?
  }
  if( number_blocks.size() == 0){
    return 0; 
  }
  return number_blocks[0];
}

bool BigInt::isEqual(BigInt number){
  // Make sure both are compacted (no 0 blocks on significant end
  compactBlocks();
  number.compactBlocks();
  if(number_blocks.size() != number.number_blocks.size()){  // Different lengths?
    return false;
  }
  for(unsigned int i = 0; i < number_blocks.size(); i++){  // Blocks should match
    if(number_blocks[i] != number.number_blocks[i]){
      return false;
    }
  }
  if(number.isNegative != isNegative){
    return false;
  }
  return true;  // Must be OK
}

bool BigInt::isLess(BigInt number){
  if(isNegative && !number.isNegative){  // negatives less than positives
    return true;
  }
  if(isNegative && number.isNegative){
    return !isLessBlocks(number);
  }else{
    return isLessBlocks(number);
  }
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
  assert(nonNegBlocks());
  assert(number.nonNegBlocks());
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

bool BigInt::isGreater(BigInt number){
  return !isLess(number);
}

void BigInt::add(BigInt number){
  assert(nonNegBlocks());
  assert(number.nonNegBlocks());
  // a + b      Make copies so we can mess them up
  BigInt a = BigInt(*this);
  BigInt b = number;
//  cout << "aa: " << a.getAsDigits() << " b: " << b.getAsDigits() << endl;
  if(isLessBlocks(b)){
//    cout << "Bigger blocks\n";
    BigInt c = a;
    a = b;
    b = c;
    a.isNegative = !a.isNegative;
    b.isNegative = !b.isNegative;
    isNegative = !isNegative;
  }
//  cout << "ba: " << a.getAsDigits() << " b: " << b.getAsDigits() << endl;
  if(a.isNegative){
    a.negateBlocks();
  }
  if(b.isNegative){
    b.negateBlocks();
  }
//  cout << "a: " << a.getAsDigits() << " b: " << b.getAsDigits() << endl;
  // Set up the addition so we always get a positive result
  
  // add from smallest to largest
  long carry = 0;
  for(unsigned int i = 0; i < a.number_blocks.size() || 
    i < b.number_blocks.size(); i++){
    long sum = carry;
    if(i <  a.number_blocks.size()){
      sum += a.number_blocks[i];
    }else{
      a.number_blocks.push_back(0);
    }
    if(i < b.number_blocks.size()){
      sum += b.number_blocks[i];
    }
    if(sum > MAX_NUM_PER_BLOCK){
      carry = sum / MAX_NUM_PER_BLOCK;
      sum = sum % MAX_NUM_PER_BLOCK;
    }else if(sum < 0){
      sum = sum + MAX_NUM_PER_BLOCK;
      carry = carry -1;
    }else{
      carry = 0;
    }
    a.number_blocks[i] = sum;
  }
  if(carry != 0){
    a.number_blocks.push_back(carry);
  }
  // copy back
  number_blocks = a.number_blocks;
}

void BigInt::subtract(BigInt number){
  number.isNegative = !number.isNegative;
  add(number);
}


void BigInt::multiply(BigInt b){
  // multiply from smallest to largest
  BigInt a = BigInt(0);
  for(unsigned int i = 0; i < number_blocks.size(); i++){
    BigInt part = BigInt(b);
    part.multiply(number_blocks[i]);
    part.multBlock(i);
    a.add(part);
  }
  number_blocks = a.number_blocks;
  // TODO: fix negativeness
}

void BigInt::multBlock(unsigned int mult){
  for(unsigned int i = 0; i < mult; i++){
    number_blocks.insert(number_blocks.begin(),0);
  }
}

void BigInt::divBlock(unsigned int div){
  for(unsigned int i = 0; i < div && i < number_blocks.size(); i++){
    number_blocks.erase(number_blocks.begin());
  }
}

void BigInt::multiply(long number){
  // multiply from smallest to largest
  long carry = 0;
  for(unsigned int i = 0; i < number_blocks.size(); i++){
    long sum = number * number_blocks[i];
    sum += carry;
    if(sum > MAX_NUM_PER_BLOCK){
      carry = sum / MAX_NUM_PER_BLOCK;
      sum = sum % MAX_NUM_PER_BLOCK;
    }else{
      carry = 0;
    }
    number_blocks[i] = sum;
  }
  number = carry;
  while(carry != 0){
    carry = number / MAX_NUM_PER_BLOCK;
    long rem = number % MAX_NUM_PER_BLOCK;
    number_blocks.push_back(rem);
    number = carry;
  }
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

void BigInt::negateBlocks(){
  for(unsigned int i = 0; i < number_blocks.size(); i++){
    number_blocks[i] =  0 - number_blocks[i];
  }
}

bool BigInt::nonNegBlocks(){
  for(unsigned int i = 0; i < number_blocks.size(); i++){
    if(number_blocks[i] < 0){
      return false;
    }
  }
  return true;
}
