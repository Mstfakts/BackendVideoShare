#ifndef VIDEOSHARE_H
#define VIDEOSHARE_H

#include <iostream>
#include "Video.h"
#include "User.h"
#include "LinkedList.h"
#include <string>

using namespace std;

class VideoShare
{

private:
	LinkedList<User> users;		//users list
	LinkedList<Video> videos;	//videos list

public:
	VideoShare();				//default constructor
	~VideoShare();				//destructor
	void createUser(const string & userName, const string & name, const string & surname);	//adds a new user to the list of users
	void loadUsers(const string & fileName);												//loads the list of user entries from the given file
	void createVideo(const string & title, const string & genre);							//adds a new video to the list of videos
	void loadVideos(const string & fileName);												//loads the list of video entries from the given file
	void addFriendship(const string & userName1, const string & userName2);					//adds a friend entry to the list of friends of both users
	void removeFriendship(const string & userName1, const string & userName2);				//deletes the friendship of both users
	void updateUserStatus(const string & userName, Status newStatus);						//updates the user status to active or suspended
	void subscribe(const string & userName, const string & videoTitle);						//if the user and video exist and user not suspended 
																							//adds a subscription entry to the list of subscriptions of the given user
	void unSubscribe(const string & userName, const string & videoTitle);					//if the user and video exist and user not suspended delete the subscription entry
	void deleteUser(const string & userName);												//deletes the user from the list of users and also deletes the mutual friendships
	void printAllUsers();																	//prints the information of all users
	void printAllVideos();																	//prints the information of all videos
	void printUserSubscriptions(const string & userName);									//prints the video information that the given user has subscribed
	void printFriendsOfUser(const string & userName);										//prints the user information that the given user has friendship
	void printCommonSubscriptions(const string & userName1, const string & userName2);		//prints the videos that are common in both given users subscriptions
	void printFriendSubscriptions(const string & userName);									//prints the subscriptions of the given user's friends
	bool isFriendOfFriend(const string & userName1, const string & userName2);				//checks if the given users are linked by first degree chain of friends 
																							//even if they are not direct friends
	bool checkUser(string userName);														//checks the existence of the user
	bool checkVideo(string videoTitle);														//checks the existence of the video
};


#endif
