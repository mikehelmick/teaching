#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primeDecomp(int number){
  if(number == 1){
    vector<int> ret;
    return ret;
  }
  for(int i = 2; i <= number; i++){
    if(number % i == 0){
      vector<int> ret = primeDecomp(number / i);
      ret.push_back(i);
      return ret ;
    }
  }
 
}

int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Enter your number on the command line.\n";
    return 0;
  }
  int number = atoi(argv[1]);
  cout << "The prime number decomposition of " << number << " is:" << endl;
  vector<int> pr = primeDecomp(number);
  for(int i = 0; i < pr.size();i++){
    cout << i << ":" << pr[i] << endl;
  }
}