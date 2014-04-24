#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class BaseballRecord {
public:
  BaseballRecord() : wins(0), losses(0) {    
  }
  
  void addWin() {
    wins++;
  }
  
  void addLoss() {
    losses++;
  }
  
  double getWinningPercentage() {
    return wins / (double)(wins + losses);
  }
  
  int predictedWins(int seasonLength) {
    return (int) (getWinningPercentage() * seasonLength);
  }
  
  string toString() {
    stringstream s;
    s << wins << "-" << losses << " "
        << setprecision(3) << fixed << getWinningPercentage();
    return s.str();
  }
  
private:
  int wins;
  int losses;

};

int main() {
  BaseballRecord r;
  r.addWin();    // now 1-0
  r.addLoss();   //     1-1
  r.addWin();    //     2-1
  r.addLoss();   //     2-2
  r.addLoss();   //     2-3
  r.addWin();    //     3-3
  r.addWin();    //     4-3
  r.addWin();    //     5-3
  cout << r.toString() << endl;
  cout << "Predicted wins this season: " << r.predictedWins(165) << endl;
}