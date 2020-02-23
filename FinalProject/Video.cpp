#include "Video.h"

Video::Video()
{
	title = "";
	genre = "";
}

Video::Video(string title, string genre)
{
	this->title = title;
	this->genre = genre;
}

Video::~Video(){}

const string& Video::getTitle() const		
{
	return title;
	
}

void Video::setTitle(const string title)
{
	this->title = title;
}

const string& Video::getGenre() const
{
	return genre;
}

void Video::setGenre(const string& genre)
{
	this->genre = genre;
}

// If video titles are same then the videos are equal.
bool Video::operator==(const Video & rhs) const	 
{
	return (title == rhs.getTitle());
}

ostream& operator<<(ostream& out, const Video &video)
{
	out << "Title: " << video.title << endl;
	out << "Genre: " << video.genre << endl;
	return out;
}

