#include <iostream>

using namespace std;

int main(){
  // Q1
  for(float a = 0; a != 9; a += 0.3){
    cout << a << endl;
    
    if(a > 20){
      break;
    }
  }
  
  // Q3
  unsigned total_points = 1834;
  unsigned num_students = 20;
  double avg_score = static_cast<double>(total_points / num_students);
  cout << "Average Score is: " << avg_score << endl;
  
  // Q4
  int a;
  cin >> a;
  cout << a * 2;
  
  // Q5
  int x = 12;
  int y = x;
  x++;
  y += x;
  y--;
  int z = x * y - 1;
  cout << "x: " << x << " y: " << y << " z: " << z << endl;
  
  // Q7
  string mystring = "This is a long string!";
  string out = "";
  for(int i = 0; i < mystring.length(); i = i + 2){
    out = out + mystring.substr(i,i+2);
  }
  cout << out;
}