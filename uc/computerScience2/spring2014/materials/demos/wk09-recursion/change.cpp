#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getChange(int money, string sofar, int len){
  //cout << "money: " << money << endl;
  if(len < 0){
    return;
  }
  if(money <= 0){
    cout << sofar << endl;
    return;
  }
  //if(step == 0){
    //cout << money ;
  //}
  if(money >= 10000){
    getChange(money - 10000, sofar + "$100 ", len -1);
  }
  if(money >= 5000){
    getChange(money - 5000, sofar + "$50 ", len -1);
  }
  if(money >= 2000){
    getChange(money - 2000,  sofar + "$20 ", len -1);
  }
  if(money >= 1000){
    getChange(money - 1000,  sofar + "$10 ", len -1);
  }
  if(money >= 500){
    getChange(money - 500,  sofar + "$5 ", len -1);
  }
  if(money >= 100){
    getChange(money - 100,  sofar + "$1 ", len -1);
  }
  if(money >= 25){
    getChange(money - 25,  sofar + "$0.25 ", len -1);
  }
  if(money >= 10){
    getChange(money - 10,  sofar + "$0.10 ", len -1);
  }
  if(money >= 5){
    getChange(money - 5,  sofar + "$0.05 ", len -1);
  }
  if(money >= 1){
    getChange(money - 1,  sofar + "$0.01 ", len -1);
  } 
  return;
}

int main(int argc, char* argv[]){
  if(argc < 3){
    cout << "Enter dollars and cents\n";
    return 0;
  }
  
  int dollars = atoi(argv[1]);
  int cents = atoi(argv[2]);
  cout << dollars << " dollar, " << cents << "cents in change:\n";
  getChange( dollars * 100 + cents,"", 5);
  
  return 0;
}