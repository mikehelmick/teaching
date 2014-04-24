#include <iostream>

using namespace std;

int main(){
  // Q2
  for(int i = 1; i <= 20; i++){   
    if(i % 2 == 0 || i > 15){
      cout << i << " ";
    }
  }
  cout << endl << endl;
  
  // Q3
  for(int i = 1 ; i <= 20; i = i + 2){   
    if( i == 2 || !(i > 15 && i < 5)){
      cout << i << " ";
    }
  }
  cout << endl << endl;
  
  // Q4
  int myCounter = 0;
  int numbers[20];
  for(int i = 1; i <= 20; i++){
    if( numbers[i] = 5){
      myCounter +1;
    }
  }
  
  // Q7
  int i = 5;
  int j = 10;
  for(i = 0; i < 20; i++){
    for(j = 1; j < i; j++){
      cout << i*j << " ";
    } 
  }

}
