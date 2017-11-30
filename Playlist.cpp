#include "Playlist.h"



Playlist::Playlist(string name = "noname"){
	playlistName = name;
}

Playlist::~Playlist()
{
}

string Playlist::GetName() {
	return playlistName;
}

void Playlist::AddSong(Song* ptr) {
	songs.push_back(ptr);
}

void Playlist::PrintSongs() { //prints LYRICS of songs, not titles, as per lab reqs
	for (unsigned int i = 0; i < songs.size(); ++i) {
		cout << songs.at(i)->GetLyrics() << endl;
		songs.at(i)->IncrementCount();
	}
}