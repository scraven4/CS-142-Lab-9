/*
	Lab 9: PLaylists
	Samuel Craven, section 02, sam.craven@byu.net
	Allows use to manipulate playlists of songs. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "Song.h"
#include "Playlist.h"

using namespace std;

void PrintOptions() {
	cout << endl << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library(and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl;
	return;
}

string AddSong(vector<Song*>& songs) {
	string songName;
	string songLyrics;
	
	cout << "Song Name:";
	getline(cin, songName);
	if (songName != "STOP") {
		cout << "Song's first line:";
		getline(cin, songLyrics);
		Song* pointer = new Song(songName, songLyrics, 0);
		songs.push_back(pointer);
	}
	return songName;
}

void AddPlaylist(vector<Playlist>& playlists) {
	string name;

	cout << "Playlist name: ";
	getline(cin, name);
	playlists.push_back(name);

	return;
}

void ListPlaylists(vector<Playlist> playlists) {
	for (unsigned int i = 0; i < playlists.size(); ++i) {
		cout << i << ": " << (playlists.at(i)).GetName() << endl;
	}

	return;
}

void ListSongsWithLyrics(vector<Song*> songs) {
	for (unsigned int i = 0; i < songs.size(); ++i) {
		cout << songs.at(i)->GetName() << ": \"" << songs.at(i)->GetLyrics() << "\", "
			<< songs.at(i)->GetCount() << " play(s)." << endl;
	}

	return;
}

void ListSongs(vector<Song*> songs) {
	for (unsigned int i = 0; i < songs.size(); ++i) {
		cout << i << ": " << songs.at(i)->GetName() << endl;
	}
	return;
}

void AddSongToPlaylist(vector<Playlist>& playlists, vector<Song*> songs) {
	int songNum = 0;
	int playlistNum = 0;
	ListPlaylists(playlists);
	cout << "Pick a playlist index number: ";
	cin >> songNum;
	ListSongs(songs);
	cout << "Pick a song index number: ";
	cin >> playlistNum;
	
	(playlists.at(playlistNum)).AddSong(songs.at(songNum));

	return;
}

void PlayPlaylist(vector<Playlist> playlists) {
	int playlistNum = 0;
	ListPlaylists(playlists);
	cout << "Pick a playlist index number: ";
	cin >> playlistNum;
	cout << endl << "Playing first lines of playlist: " << (playlists.at(playlistNum)).GetName() << endl;
	(playlists.at(playlistNum)).PrintSongs();
}

int main() {
	string menuChoice;
	vector<Song*> songs;
	vector<Playlist> playlists;
	string check;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;
	while (menuChoice != "quit") {
		cout << endl << "Enter your selection now: ";
		cin >> menuChoice;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); //prep for getlines later
		if (menuChoice == "add") {
			cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
			while (check != "STOP") {
				check = AddSong(songs);
			}
		}
		else if (menuChoice == "list") {
			ListSongsWithLyrics(songs);
		}
		else if (menuChoice == "addp") {
			AddPlaylist(playlists);
		}
		else if (menuChoice == "addsp") {
			AddSongToPlaylist(playlists, songs);
		}
		else if (menuChoice == "listp") {
			ListPlaylists(playlists);
		}
		else if (menuChoice == "play") {
			PlayPlaylist(playlists);
		}
		else if (menuChoice == "delp") {}
		else if (menuChoice == "delsp") {}
		else if (menuChoice == "delsl") {}
		else if (menuChoice == "options") {
			PrintOptions();
		}
		else if (menuChoice != "quit") {
			PrintOptions();
		}
	}
	
	for (unsigned int i = 0; i < songs.size(); ++i) {
		delete songs.at(i); //free up memory spaces allocated by new 
	}

	cout << "Goodbye!" << endl;

	return 0;
}