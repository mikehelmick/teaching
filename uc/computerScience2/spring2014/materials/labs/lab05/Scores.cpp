#include <Scores.h>
#include <cstdlib>


Scores::Scores() : scores(NULL), size(0), capacity(0) {
}

Scores::~Scores() {
  if (scores != NULL) {
    delete scores;
  }
}
  
void Scores::addScore(int score) {
  growArray();
  scores[size++] = score;
}
  
int Scores::getScoreAt(int index) const {
  if (index < 0 || index >= size) {
    return -1;
  }
  return scores[index];
}
  
int Scores::getSize() const {
  return size;
}
  
int Scores::getCapacity() const {
  return capacity;
}
  
int Scores::getMinimum() const {
  if (size == 0) {
    return -1;
  }
  int min = scores[0];
  for (int i = 1; i < size; i++) {
    if (scores[i] < min) {
      min = scores[i];
    }
  }
  return min;
}
  
int Scores::getMaximum() const {
  if (size == 0) {
    return -1;
  }
  int max = scores[0];
  for (int i = 1; i < size; i++) {
    if (scores[i] > max) {
      max = scores[i];
    }
  }
  return max;
}

double Scores::getAverage() const {
  if (size == 0) {
    return 0;
  }
  double total = 0;
  for (int i = 0; i < size; i++) {
    total += scores[i];
  }
  return total / size;
}

int Scores::countScoresInRange(int min, int max) const {
  if (size == 0) {
    return 0;
  }
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (scores[i] >= min && scores[i] < max) {
      count++;
    }
  }
  return count;
}
  
void Scores::growArray() {
  if (scores == NULL) {
    scores = new int[1];
    capacity = 1;
    size = 0;
  } else if (size == capacity) {
    capacity *= 2;
    int* newScores = new int[capacity];
    for (int i = 0; i < size; i++) {
      newScores[i] = scores[i];
    }
    delete scores;
    scores = newScores;
  }
}
