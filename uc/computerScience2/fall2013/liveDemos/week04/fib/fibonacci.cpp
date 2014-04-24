#include <fibonacci.h>

Fibonacci::Fibonacci() {
  // Initialize first to spots in the fibinacci sequence.
  memo.push_back(0);
  memo.push_back(1);
}

unsigned long Fibonacci::getFib(unsigned short x) {
  return fib_r(x);
}

const vector<unsigned long> Fibonacci::getCallCount() {
  return calls;
}

void Fibonacci::resetCallCount() {
  calls.resize(0);
}

// PRIVATE
unsigned long Fibonacci::fib_r(unsigned int x) {
  resize(x);
  // keeping track of calls for X
  calls[x]++;
  
  if (x == 0) {
    return 0;
  }

  if (memo[x] > 0) {
    return memo[x];
  }
  memo[x] = fib_r(x - 1) + fib_r(x - 2);
  return memo[x];
}

// Ensure capacity in the memo vector
void Fibonacci::resize(unsigned int x) {
  unsigned int arrSize = x + 1;
  if (memo.size() < arrSize) {
    memo.resize(arrSize);
  }
  if (calls.size() < arrSize) {
    calls.resize(arrSize);
  }
}






