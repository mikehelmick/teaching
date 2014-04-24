#include <iostream>
#include <cstdlib>
using namespace std;

long calculate( long i, long j ) {
  if ( j == 1 ) {
    return i;
  } else {
    return i * calculate( i, j - 1 );
  }
}
   
long calculate( long i ) {
  return calculate( i, i );
}

int main(int argc, char* argv[]) {
  cout << calculate(atoi(argv[1])) << endl;
}