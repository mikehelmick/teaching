/**   @file main.cpp    
      @author Paul Talaga
      @date 10-11-2013
      
      Main driver program for the gradebook program.
      */
      
#include <Gradebook.h>

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  // Ensure that the input and output filenames are passed in.
  if (argc != 3) {
    cout << " You mut pass an input and output filename on the command line." << endl;
    return 1;
  }  

  Gradebook gb(argv[1]);
  
  ofstream out;
  
  out.open(argv[2]);
  
  out.width(20);
  out << "Input File: " << gb.getSourceFile() << endl;
  out.width(20);
  out << "Score count: " << gb.getCount() << endl;
  out.width(20);
  out << "Mean: " << gb.getMean() << endl;
  out.width(20);
  out << "stdDev: " << gb.getStdDev() << endl;
  out.width(20);
  out << "Max: " << gb.getMax() << endl;
  out.width(20);
  out << "Min: " << gb.getMin() << endl;
  out.width(20);
  out << "A: " << gb.scoresInRange(90,100) << endl;
  out.width(20);
  out << "B: " << gb.scoresInRange(80,90) << endl;
  out.width(20);
  out << "C: " << gb.scoresInRange(70,80) << endl;
  out.width(20);
  out << "D: " << gb.scoresInRange(50,70) << endl;
  out.width(20);
  out << "F: " << gb.scoresInRange(0,50) << endl;
  
  out.close();
  
  return 0;
}