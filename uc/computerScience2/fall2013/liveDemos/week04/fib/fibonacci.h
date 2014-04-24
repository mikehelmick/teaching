#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <vector>

using namespace std;

class Fibonacci {
public:
  Fibonacci();

  unsigned long getFib(unsigned short x);

  const vector<unsigned long> getCallCount();

  void resetCallCount();

private:
  vector<unsigned long> memo;
  vector<unsigned long> calls;

  unsigned long fib_r(unsigned int x);
  void resize(unsigned int x);
};

#endif
