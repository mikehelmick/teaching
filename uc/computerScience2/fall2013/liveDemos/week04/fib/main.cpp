#include <iostream>
#include <time.h>
#include <fibonacci.h>

using namespace std;

int fib_r(int x, int calls[]) {
  calls[x]++;
  // base conditions
  if (x == 0) {
    return 0;
  }
  if (x == 1) {
    return 1;
  }

  return fib_r(x - 1, calls) + fib_r(x - 2, calls);
}

void init_calls(int calls[], int size) {
  for (int i = 0; i <= size; i++) {
    calls[i] = 0;
  }
}

int main() {
  const int x = 10000;
  const int arr_size = x + 1;
  int calls[arr_size];
  init_calls(calls, arr_size);

  Fibonacci fibonacci;
  for (int i = 0; i < 5; i++) {
    clock_t start = clock();
    //int fib = fib_r(x, calls);
    unsigned long fib = fibonacci.getFib(x);
    clock_t end = clock();
    clock_t elapsed = end - start;
    cout << "run=" << i << " - fib_r(" << x << ")=" << fib << " time=" << elapsed << " ticks" << endl;
  }
  //cout << endl << "calls:" << endl;
  //for (int i = 0; i < arr_size; i++) {
  //  cout << i << " -- " << calls[i] << endl;
  //}
  vector<unsigned long> mcalls = fibonacci.getCallCount();
  for (int i = 0; i < mcalls.size(); i++) {
    cout << i << " -- " << mcalls[i] << endl;
  }
}



