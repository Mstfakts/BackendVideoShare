#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>

using namespace std;

class Video {

private:
	string title;		//video title
	string genre;		//video genre

public:
	Video();			//default constructor
	Video(string title, string genre = "");		//parameterized constructor(optional genre)
	~Video();			//destructor

	const string& getTitle() const;				//gets the title of the video
	void setTitle(const string  title);			//sets the title of the video 
	const string& getGenre() const;				//gets the genre of the video
	void setGenre(const string& genre);			//sets the genre of the video
	bool operator==(const Video & rhs) const;	//overloaded operator checks if the two videos are the same
	friend ostream& operator << (ostream  &out, const Video & video);	//overloaded operator prints the characteristic of video
};

#endif