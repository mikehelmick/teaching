#ifndef SCORES_H
#define SCORES_H

/**
 * A class that represents a dynamically growable list of test scores.
 *
 */
class Scores {
public:
  /**
   * Initially empty. The initial array will be NULL, capacity zero.
   */
  Scores();
  
  // Destructor
  virtual ~Scores();
  
  void addScore(int score);
  
  int getScoreAt(int index) const;
  
  int getSize() const;
  
  int getCapacity() const;
  
  int getMinimum() const;
  
  int getMaximum() const;
  
  double getAverage() const;
  
  int countScoresInRange(int min, int max) const;

private:
  // Dynamic array
  int *scores;
  int size;
  int capacity;
  
  void growArray();
};

#endif
