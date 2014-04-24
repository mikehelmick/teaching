/**   @file Gradebook.cpp    
      @author Mike Helmick    // Change me!
      @date 10-01-2013        // Change me!
      
      Implementation of the Gradebook class
      */

#include <Gradebook.h>

#include <math.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Gradebook::Gradebook() {
  filename = "";
  nextPos = 0;
  capacity = 1;
  grades = new double[1];
}

Gradebook::Gradebook(const string &filename) {
  this->filename = filename;
  nextPos = 0;
  capacity = 1;
  grades = new double[1];
  
  ifstream file;
  file.open(filename.c_str());
  if(file.fail()){
    cout << "Error opening " << filename << endl;
  }
  double temp;
  while(file >> temp){
    addScore(temp);
  }
  file.close();
}

Gradebook::Gradebook(const Gradebook &that) {
  filename = that.filename;
  nextPos = that.nextPos;
  capacity = that.capacity;
  grades = new double[capacity];
  for(int i = 0; i < nextPos; i++){
    grades[i] = that.grades[i];
  }
}

Gradebook::~Gradebook() {
  delete[] grades;
  grades = NULL;
}

void Gradebook::addScore(double grade) {
  //cout << nextPos << ":" << capacity << ":" << grade << endl;
  if(nextPos == capacity){  // make bigger!
    enlarge();
  }
  grades[nextPos] = grade;
  nextPos++;
}

double Gradebook::getScoreAt(int i) {
  if(i < 0 || i >= nextPos){  // Outside bounds
    return -1;
  }
  return grades[i];
}

int Gradebook::getCount() {
  return nextPos;
}

string Gradebook::getSourceFile() {
  return filename;
}  

double Gradebook::getMean() {
  if(nextPos == 0){ // no numbers!
    return -1;
  }
  double sum = 0.0;
  for(int i = 0; i < nextPos; i++){
    sum += grades[i];
  }
  return sum/static_cast<double>(nextPos);
}

double Gradebook::getMin() {
  if(nextPos == 0){ // no numbers!
    return -1;
  }
  double min = grades[0];
  for(int i = 0; i < nextPos; i++){
    if(min > grades[i]){
      min = grades[i];
    }
  }
  return min;
}

double Gradebook::getMax() {
if(nextPos == 0){ // no numbers!
    return -1;
  }
  double max = grades[0];
  for(int i = 0; i < nextPos; i++){
    if(max < grades[i]){
      max = grades[i];
    }
  }
  return max;
}

int doubleCompare (const void* a, const void* b){
  if( *static_cast<const double*>(a) < *static_cast<const double*>(b) ){   
    // a < b
    return -1;
  }else if( *static_cast<const double*>(a) > *static_cast<const double*>(b) ){   
    // a > b
    return 1;
  }else{   // must be equal!
    return 0;
  }
}

double Gradebook::getMedian() {
  if(nextPos == 0){ // no numbers!
    return -1;
  }
  // This solution will keep grades in the original order,
  // by copying the values to a new array, sorting,
  // and then find the median
  
  double* tempGrades = new double[nextPos];
  
  // copy grades to new
  for(int i = 0; i < nextPos; i++){
    tempGrades[i] = grades[i];
  }
  
  // sort using qsort http://www.cplusplus.com/reference/cstdlib/qsort/
  qsort(tempGrades, nextPos, sizeof(double), doubleCompare);
  
  double ret = tempGrades[nextPos/2];
  delete[] tempGrades;
  
  return ret;
}

double Gradebook::getStdDev() {
  if(nextPos == 0){ // no numbers!
    return -1;
  }
  double sum = 0.0;
  double sumsquared = 0.0;
  for(int i = 0; i < nextPos; i++){
    sum += grades[i];
    sumsquared += grades[i] * grades[i];
  }
  double cnt = static_cast<double>(nextPos);
  return sqrt((sumsquared / cnt) - (sum / cnt) * (sum / cnt));
}

int Gradebook::scoresInRange(double low, double high) {
  int cnt = 0;
  for(int i = 0; i < nextPos; i++){
    if(low <= grades[i] && grades[i] < high){
      cnt++;
    } 
  }
  return cnt;
}

void Gradebook::enlarge(){
  // Double the size of the array
  double* newarray = new double[capacity * 2];
  // Copy data over
  for(int i = 0; i < capacity; i++){
    newarray[i] = grades[i];
  }
  // delete old memory
  delete[] grades;
  grades = newarray;
  capacity = capacity * 2;
  //cout << "Capacity: " << capacity << endl;
}
