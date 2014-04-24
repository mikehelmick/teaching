// week13/ex05
#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
public:
  Song(string artist, string title);

  virtual ~Song();

  Song(const Song &that);

  string getArtist() const;

  string getTitle() const;

  string toString() const;

private:
  string artist;
  string title;
};

#endif