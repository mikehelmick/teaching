#include <iostream>
using namespace std;

#include <Song.h>

Song* readSong() {
  cout << "Artist? ";
  string artist;
  getline(cin, artist);
  cout << "Title? ";
  string title;
  getline(cin, title);

  Song* song = new Song(artist, title);
  return song;
}

int main() {
  Song* songA = readSong();
  cout << songA->toString() << endl;

  // Pointer assignment!
  Song* songB = songA;
  cout << songB->toString() << endl;

  cout << "a: " << songA << " b: " << songB << endl;
 
  delete songA;
  // Same addresses
  cout << "a: " << songA << " b: " << songB << endl;
}




