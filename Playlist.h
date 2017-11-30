#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Song.h"
using namespace std;
class Playlist
{
public:
	Playlist(string name);
	~Playlist();
	string GetName();
	void AddSong(Song* ptr);
	void PrintSongs(); //prints LYRICS of songs, not titles, as per lab reqs
private:
	vector<Song*> songs;
	string playlistName;
};

