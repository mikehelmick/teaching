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
  double *grades;
  int capacity;
  int size;
  string *filename;

  void resize();
  void copy(double *from, double *to, const int &numElements);
};

#endif