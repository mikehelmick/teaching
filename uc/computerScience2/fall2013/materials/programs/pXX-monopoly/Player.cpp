#include <Player.h>

int space;
bool inJail;
bool chanceOutOfJail;
bool comChestOutOfJail;

Player::Player()
    : space(0), turnsInJail(0), inJail(false), chanceOutOfJail(false), comChestOutOfJail(false) {
  
}

Player::~Player() {
  // nothing to do
}
  
int Player::getSpace() const {
  return space;
}

void Player::setSpace(int newSpace) {
  space = newSpace;
  inJail = false;
  turnsInJail = 0;
}

int Player::getTurnsInJail() {
  return turnsInJail;
}

void Player::addTurnInJail() {
  turnsInJail++;
}

void Player::moveToJail(int spaceNum) {
  space = spaceNum;
  turnsInJail = 0;
  inJail = true;
}

bool Player::isInJail() const {
  return inJail;
}

bool Player::hasGetOutOfJail() const {
  return chanceOutOfJail || comChestOutOfJail;
}

bool Player::hasChanceGetOutOfJail() const {
  return chanceOutOfJail;
}

bool Player::hasComChestOutOfJail() const {
  return comChestOutOfJail;
}

void Player::awardChanceOutOfJail() {
  chanceOutOfJail = true;
}

void Player::awardComChestOutOfJail() {
  comChestOutOfJail = true;
}

// Uses chance and then com chest if in posssision of both.
void Player::useOutOfJailCard() {
  if (chanceOutOfJail) {
    chanceOutOfJail = false;
  } else if (comChestOutOfJail) {
    comChestOutOfJail = false;
  }
}
