/**   @file Gradebook.h    
      @author Paul Talaga
      @date 10-11-2013        
      
      Interface for the Gradebook class.
      */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
using namespace std;

class Gradebook {
public:
  Gradebook();

  Gradebook(const string &filename);
 
  Gradebook(const Gradebook &that);

  virtual ~Gradebook();

  void addScore(double grade);

  double getScoreAt(int i);

  int getCount();

  string getSourceFile();

  double getMean();

  double getMin();

  double getMax();

  double getMedian();

  double getStdDev();

  int scoresInRange(double low, double high);
  
private:

  string filename;

  int nextPos;  // Next index to put a grade, # grades so far
  int capacity; // Max capacity for the current grades array
  double* grades; // Where all the grades are stored
                  // Pointer to an array on the heap
                  
  void enlarge(); // Private function to enlarge (double) the
                  // size of the array
};

#endif