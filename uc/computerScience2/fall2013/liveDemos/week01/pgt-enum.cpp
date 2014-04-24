#include <iostream>

using namespace std;

enum Dir {North, South, East, West};

int main(){
  Dir mydir = East;
  Dir otherdir = West;
  if(mydir == 2 ){ // DON'T DO THIS
    cout << "they match!\n";
  }else if(mydir == otherdir){
    cout << "they don't match :-( \n";
  }else{
    cout << "Something\n";
  }
  cout << "Dir length: " << sizeof(Dir) << endl;
  return 0;
}
