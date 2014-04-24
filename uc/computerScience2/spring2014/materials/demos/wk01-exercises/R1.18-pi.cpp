/**   @file R1.18-pi.cpp    
      @author Paul Talaga 
      @date 08-21-2013  
      @version 0.01   */
      
/*
  This program estimates pi with the infinite sum:
  pi/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 ....
  num_terms determines the number of terms and therefore the accuracy.
*/

#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){

  const int num_terms = 50000;
  
  double sum = 0;
  for(int i = 0; i < num_terms; i++){
    double term;
    term = 1 / (float(i) * 2 + 1);  
    if(i % 2 == 0){
      // Add term
      //sum = sum + term;
      sum += term;  // or
    }else{
      // Subtract term
      //sum = sum - term;
      sum -= term; // or
    }
  }

  cout << "Pi estimate (" << num_terms << " terms): " << sum * 4 << endl;
  
  return 0;
}