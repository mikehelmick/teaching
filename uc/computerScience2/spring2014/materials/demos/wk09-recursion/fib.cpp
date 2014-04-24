#include <iostream>
#include <vector>

using namespace std;


/* Calculates the nth Fibonacci number using the straight recurrence relation:
  f(n) = f(n-1) + f(n-2)   where f(0) = 0 and f(1) = 1
  */
int fib1(int n, vector<int>& count){
  count[n]++;
  if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    return fib1(n-1, count) + fib1(n-2, count);
  }
}

unsigned long fib2Helper(int, int, unsigned long, unsigned long, vector<int>&);
/* Calculates the nth Fibonacci number using a recursive helper function,
  but goes in reverse and passes extra information forward to minimize 
  duplicate work.
  */
unsigned long fib2(int n, vector<int>& count){
  return fib2Helper(n, 2, 0, 1, count);
}

unsigned long fib2Helper(int goal, int current, unsigned long n2, unsigned long n1, vector<int>& count){
  //count[current]++;
  if (goal <= current){
    return n1+n2;
  }
  return fib2Helper(goal, current + 1, n1, n1 + n2, count);
}

int main(int argc, char* argv[]){
  if( argc != 2){
    cout << "Enter fib of n.  ./a.out 5\n";
    return 0;
  }
  int n = atoi(argv[1]);
  //cout << "Fib of " << n << endl;
  
  // Set up counters
  vector<int> count;
  for(int i = 0; i < n; i++){
    count.push_back(0);
  }
  for(int i = 1; i <= n ; i++){
    cout << "f(" << i << ") = " << fib2(i, count) << endl;
  }
  
  // Now print out counts
 /* for(int i = 0; i < n; i++){
    cout << i << ":" << count[i] << " ";
  }*/
  cout << endl;
  return 0;
}