#include <iostream>

using namespace std;

/* GCD computed using the Euclidean algorithm */

int gcd(int a, int b){
  if( b == 0){
    return a;
  }
  return gcd(b, a%b);
}

int main(int argc, char* argv[]){
  if(argc != 3){
    cout << "Enter to values on the command line\n";
    return 0;
  }
  cout << gcd(atoi(argv[1]),atoi(argv[2])) << endl;
}