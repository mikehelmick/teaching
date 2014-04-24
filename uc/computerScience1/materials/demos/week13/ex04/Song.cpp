#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include <Song.h>

Song::Song(string artist, string title) {
  cout << "Song::Song(string, string)" << endl;
  this->artist = artist;
  this->title = title;
}

Song::~Song() {
  cout << "Song::~Song()" << endl;
}

Song::Song(const Song &that) {
  cout << "Song::Song(Song&)" << endl;
  this->artist = that.artist;
  this->title = that.title;
}

string Song::getArtist() const {
  return artist;
}

string Song::getTitle() const {
  return title;
}

string Song::toString() const {
  stringstream ss;
  ss << title << " by " << artist;
  return ss.str();
}
