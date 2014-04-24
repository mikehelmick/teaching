#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

/* Reads in the file from command-line, or stdin
 * Outputs to stdout
 * Ctrl-d to end input from stdin
 */
main(int argc, char* argv[]){
  
  ifstream file;
  istream* data;
  
  if(argc > 1){ // got filename
    file.open(argv[1]);
    data = static_cast<istream *>(&file); 
  }else{
    data = static_cast<istream *>(&cin);
    cout << "Enter a series of numbers, followed by Ctrl-d to end.\n";
  }
  
  // Set up counters
  int count = 0;
  int sum = 0;
  int sum2 = 0;
  
  int number = 0;
  
  while( *data >> number ){
    //cout << number << endl;
    count++;
    sum += number;
    sum2 += number * number;
  }
  
  if(argc > 1){
    file.close();
  }
  
  cout << "N: " << count << " Sum: " << sum << " Squared Sums: " << sum2 << endl;
  
  // Calculate stdev
  double avg = static_cast<double>(sum) / static_cast<double>(count);
  double avgsquares = static_cast<double>(sum2) / static_cast<double>(count);
  
  cout << "Average: " << avg << endl;
  cout << "Std dev: " << sqrt(avgsquares - (avg * avg)) << endl; 
  
}
