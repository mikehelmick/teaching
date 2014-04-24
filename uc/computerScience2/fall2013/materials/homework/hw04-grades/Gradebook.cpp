#include <Gradebook.h>

#include <math.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Gradebook::Gradebook() : grades(NULL), capacity(0), size(0), filename(NULL) {
  
}

Gradebook::Gradebook(const string &filename) : grades(NULL), capacity(0), size(0) {
  this->filename = new string(filename);

  ifstream inFile;
  inFile.open(filename.c_str(), ios::in);

  double grade;
  while(!inFile.eof()) {
    inFile >> grade;
    addScore(grade);
  }
  
  inFile.close();
}

Gradebook::Gradebook(const Gradebook &that) : grades(NULL), filename(NULL) {
  for (int i = 0; that.size; i++) {
    this->addScore(that.grades[i]);
  }
}

Gradebook::~Gradebook() {
  if (grades != NULL) {
    delete grades;
  }
  if (filename != NULL) {
    
  }
}

void Gradebook::addScore(double grade) {
  resize();
  int insertPos = size;
  size++;
  
  while (insertPos > 0 && grade < grades[insertPos - 1]) {
    grades[insertPos] = grades[insertPos - 1];
    insertPos--;
  }
  grades[insertPos] = grade;
}

double Gradebook::getScoreAt(int i) {
  if (i < 0 || i >= size) {
    return -1;
  }
  return grades[i];
}

int Gradebook::getCount() {
  return size;
}

string Gradebook::getSourceFile() {
  string result = "";
  if (filename != NULL) {
    result = *filename;
  }
  return result;
}

double Gradebook::getMean() {
  if (size == 0) {
    return 0;
  }
  double total = 0.0;
  for (int i = 0; i < size; i++) {
    total += grades[i];
  }
  return total/size;
}

double Gradebook::getMin() {
  if (size == 0) {
    return 0;
  }
  return grades[0];
}

double Gradebook::getMax() {
  if (size == 0) {
    return 0;
  }
  return grades[size-1];
}

double Gradebook::getMedian() {
  if (size == 0) {
    return 0;
  }
  // sorted, median is middle value;
  return grades[size/2];
}

double Gradebook::getStdDev() {
  if (size == 0) {
    return 0;
  }

  double sumSquares = 0.0;
  double mean = getMean();
  for (int i = 0; i < size; i++) {
    double thisDiff = grades[i] - mean;
    sumSquares += (thisDiff * thisDiff);
  }
  return sqrt(sumSquares/size);
}

int Gradebook::scoresInRange(double low, double high) {
  int begRange = 0;
  int endRange = size - 1;
 
  while (grades[begRange] < low && begRange < endRange) {
    begRange++;
  }
  while (grades[endRange] >= high && endRange >= begRange) {
    endRange--;
  }

  int result = endRange - begRange;
  if (result < 0) {
    result = 0;
  } else {
    result++;
  }
  return result;
}

void Gradebook::resize() {
  if (size == capacity) {
    // time to resize
    if (capacity == 0) {
      capacity = 1;
    } else {
      capacity *= 2;
    }

    // Allocate new array
    double* tmp = new double[capacity];
    copy(grades, tmp, size);
    delete grades;
    grades = tmp;
  }
}

void Gradebook::copy(double *from, double *to, const int &numElements) {
  for (int i = 0; i < numElements; i++) {
    to[i] = from[i];
  }
}
