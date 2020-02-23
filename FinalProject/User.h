#ifndef USER_H
#define USER_H

#include <iostream>
#include "Video.h"
#include "LinkedList.h"
#include <string>

using namespace std;

enum Status		//User status active or suspended
{
	ACTIVE,
	SUSPENDED
};



class User
{
private:
	string username;					//username or nickname
	string name;						//real name of the user
	string surname;						//real surname of the user
	Status status;						//user status active or suspended
	LinkedList<Video*> subscriptions;	//references of videos a user has subscribed
	LinkedList<User*> friends;			//references of friends of the user

public:
	User();								//default constructor
	User(string username, string name="", string surname="");		//parameterized constructor(optional name and surname)
	~User();														//destructor
	const string& getUsername() const;								//gets the username of the user
	const string& getName() const;									//gets the real name of the user
	const string& getSurname() const;								//gets the real surname of the user
	Status getStatus() const;										//gets the current status of the user
	void updateStatus(Status st);									//changes the current status
	void subscribe(Video *video);									//adds the given video pointer to the list of subscriptions
	void unSubscribe(Video *video);									//deletes the video pointer from user's subscription list
	void addFriend(User *user);										//adds the given user pointer to the list of friends
	void removeFriend(User *user);									//deletes the user pointer from the user's friend list
	LinkedList<Video*> *getSubscriptions();							//returns the pointer of the list of subscriptions
	LinkedList<User*> *getFriends();								//returns the pointer of the list of friends
	void printSubscriptions(const string &username);				//prints the subscriptions of the user
	void printFriends(const string &username);						//prints the friends of the user
	bool operator == (const User & rhs)const;						//overloaded operator checks if the users are the same
	friend ostream& operator << (ostream& out, const User &user);	//overloaded operator prints the characteristic of user
};

#endif
