#pragma once
#include <string>
using namespace std;

class Song
{
public:
	Song(string name, string lyrics, int count);
	~Song();
	void Song::SetName(string name);
	string Song::GetName() const;
	void Song::SetLyrics(string lyrics);
	string Song::GetLyrics() const;
	void Song::IncrementCount();
	void Song::SetCount(int count);
	int Song::GetCount() const;
private:
	int playCount = 0;
	string songName;
	string songLyrics;
};

