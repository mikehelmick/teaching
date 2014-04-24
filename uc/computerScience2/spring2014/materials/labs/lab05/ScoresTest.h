#ifndef SCORES_TEST_H
#define SCORES_TEST_H

#include <Scores.h>

#include <cxxtest/TestSuite.h>

using namespace std;

class ScoresTest : public CxxTest::TestSuite {
public:
  void testConstructor() {
    Scores s;
    TS_ASSERT_EQUALS(0, s.getSize());
  }
  
  void testAddOneScore() {
    Scores s;
    s.addScore(50);
    // Array should be initialized, initial capacity of 1, and size of 1
    TS_ASSERT_EQUALS(1, s.getSize());
    TS_ASSERT_EQUALS(1, s.getCapacity());
    TS_ASSERT_EQUALS(50, s.getScoreAt(0));
  }
  
  void testSimpelResize() {
    Scores s;
    s.addScore(50);
    s.addScore(60);
    TS_ASSERT_EQUALS(2, s.getSize());
    TS_ASSERT_EQUALS(2, s.getCapacity());
    TS_ASSERT_EQUALS(50, s.getScoreAt(0));
    TS_ASSERT_EQUALS(60, s.getScoreAt(1));
  }
  
  void testGetMinAndMaxPos1() {
    Scores s;
    s.addScore(1);
    s.addScore(50);
    s.addScore(100);
    
    TS_ASSERT_EQUALS(1, s.getMinimum());
    TS_ASSERT_EQUALS(100, s.getMaximum());
  }
  
  void testGetMinAndMaxPos2() {
    Scores s;
    s.addScore(100);
    s.addScore(50);
    s.addScore(1);
    
    TS_ASSERT_EQUALS(1, s.getMinimum());
    TS_ASSERT_EQUALS(100, s.getMaximum());
  }
  
  void testGetMinAndMaxPosMid() {
    Scores s;
    s.addScore(50);
    s.addScore(50);
    s.addScore(1);  
    s.addScore(100);
    s.addScore(50);
    s.addScore(50); 
    
    TS_ASSERT_EQUALS(1, s.getMinimum());
    TS_ASSERT_EQUALS(100, s.getMaximum());
  }
  
  void testGetAverage() {
    Scores s;
    for (int i = 90; i <= 100; i++) {
      s.addScore(i);
    }
    TS_ASSERT_DELTA(95.0, s.getAverage(), 0.0001);
  }
  
  void testCountScoresInRange() {
    Scores s;
    for (int i = 0; i < 10; i++) {
      for (int score = 65; score < 100; score += 10) {
        s.addScore(score);
      }
    }
    TS_ASSERT_EQUALS(10, s.countScoresInRange(60, 70));
    TS_ASSERT_EQUALS(10, s.countScoresInRange(70, 80));
    TS_ASSERT_EQUALS(10, s.countScoresInRange(80, 90));
    TS_ASSERT_EQUALS(10, s.countScoresInRange(90, 101));
  }

  void testAddLotsOfScores() {
    srand(time(NULL));
    Scores s;
    int minGen = 100;
    int maxGen = 1;
    double total = 0;
    int eightyTwo = 0;
    for (int i = 0; i < 130000; i++) {
      // scores bettwen 1 and 100, inclusive
      int score = rand() % 100 + 1;
      total += score;
      s.addScore(score);
      if (score == 82) {
        eightyTwo++;
      }
      if (score < minGen) {
        minGen = score;
      }
      if (score > maxGen) {
        maxGen = score;
      }
    }
    // check state
    TS_ASSERT_EQUALS(130000, s.getSize());
    // Net power of 2 that is above 130,000
    TS_ASSERT_EQUALS(131072, s.getCapacity());
    TS_ASSERT_EQUALS(minGen, s.getMinimum());
    TS_ASSERT_EQUALS(maxGen, s.getMaximum());
    TS_ASSERT_DELTA(total / 130000, s.getAverage(), 0.01);
    TS_ASSERT_EQUALS(eightyTwo, s.countScoresInRange(82, 83));
  }
};

#endif
