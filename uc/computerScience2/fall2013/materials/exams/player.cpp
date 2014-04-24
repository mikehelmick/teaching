#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Captain;
  
class Player {
public:
  Player(string name, int id)
      : name(name), idNumber(id), mentor(NULL) {}  
  void setMentor(Captain* mentor) {
    this->mentor = mentor;
  }  
  virtual void print() { cout << "Player: " << name << endl; }
protected:
  string name;
  int idNumber;
  // Pointer to a mentor, could be NULL if no mentor
  Captain* mentor;
};

class Captain : public Player {
public:
  Captain(string name, int id) : Player(name, id) {
  } 
  virtual void print() { cout << "Captain: " << name << endl; }
  vector<Player*> getMentoredPlayers() {
    return players;
  }
  void addMentoringResponsibility(Player* p) {
    p->setMentor(this);
    players.push_back(p);
  }
  void removeMentoringResponsibility(Player* p) {
    for (int i = 0; i < players.size(); i++) {
      if (players.at(i) == p) {
        players.erase(players.begin() + i);
        break;
      }
    }
    p->setMentor(NULL);
  }
private:
  vector<Player*> players;
};

int main() {
  /*
  Player p("Jim", 1);
  Captain c("Pam", 2);
  c = p;
  */
  
  /*
  Player p("Jim", 1);
  Captain c("Dwight", 2);
  vector<Player> v;
  v.push_back(p);
  v.push_back(c);
  for (unsigned int i = 0; i < v.size(); i++) {
    v[i].print();
  } 
  */ 
  
  Player* p = new Player("Jim", 1);
  Player* c = new Captain("Dwight", 2);
  vector<Player*> v;
  v.push_back(p);
  v.push_back(c);
  for (unsigned int i = 0; i < v.size(); i++) {
    v[i]->print();
  }  
}