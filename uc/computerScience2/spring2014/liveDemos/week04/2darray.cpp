#include <iostream>

using namespace std;

const int DIM = 20;

int getValue(int* table, int x, int y){

  return *(table + DIM * x + y);
}

void setValue(int* table, int x, int y, int value){
  *(table + DIM * x + y) = value;
}

void printTable(int* table){
  cout.width(5);
  for(int y = 0; y < DIM; y++){
    for(int x = 0; x < DIM; x++){
      cout.width(5);
      cout <<  getValue(table, x,y);
    }
    cout << endl;
  }
}

// table is a poitner to a 2 dimensional array of size DIMxDIM
void fillTable(int* table[]){
  for(int y = 0; y < DIM; y++){
    for(int x = 0; x < DIM; x++){
      setValue(table, x,y, x * y);
    }
  }
}


main(){
 int table[DIM][DIM];
 
 fillTable(table);
 printTable(table);

}
