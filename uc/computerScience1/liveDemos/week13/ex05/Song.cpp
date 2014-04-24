#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include <Song.h>

Song::Song(string artist, string title) {
  cout << "constructor - this=" << this << endl;
  this->artist = artist;
  this->title = title;
}

Song::Song(const Song &that) {
  this->artist = that.artist;
  this->title = that.title;
}

Song::~Song() {
  // Nothing to do at this time.
}

string Song::getArtist() const {
  return artist;
}

string Song::getTitle() const {
  return title;
}

string Song::toString() const {
  stringstream ss;
  ss << "Artist: " << artist
      << " Title: " << title;
  return ss.str();
}
