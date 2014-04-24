#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
  Player();
  virtual ~Player();
  
  int getSpace() const;
  void setSpace(int newSpace);
  void moveToJail(int spaceNum);

  bool isInJail() const;

  int getTurnsInJail();
  void addTurnInJail();

  bool hasGetOutOfJail() const;
  bool hasChanceGetOutOfJail() const;
  bool hasComChestOutOfJail() const;

  void awardChanceOutOfJail();
  void awardComChestOutOfJail();

  // Uses chance and then com chest if in posssision of both.
  void useOutOfJailCard();

private:
  int space;
  int turnsInJail;
  bool inJail;
  bool chanceOutOfJail;
  bool comChestOutOfJail;
};

#endif