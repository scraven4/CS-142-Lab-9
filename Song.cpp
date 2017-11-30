#include "Song.h"
#include <string>

Song::Song(string name = "none", string lyrics = "none", int count = 0){
	songName = name;
	songLyrics = lyrics;
	playCount = count;
}


Song::~Song() {
}

void Song::SetName(string name) {
	songName = name;
	return;
}
string Song::GetName() const {
	return songName;
}
void Song::SetLyrics(string lyrics) {
	songLyrics = lyrics;
}
string Song::GetLyrics() const {
	return songLyrics;
}
void Song::IncrementCount() {
	++playCount;
	return;
}
void Song::SetCount(int count) {
	playCount = count;
	return;
}
int Song::GetCount() const {
	return playCount;
}