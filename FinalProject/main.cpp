#include <iostream>
#include <string>
#include "Video.h"
#include "User.h"
#include "LinkedList.h"
#include "VideoShare.h"


int main()
{	
	VideoShare program = VideoShare();
	
	//Users
	program.createUser("mrtckmk", "MertCan", "Cakmak");
	program.createUser("mstakts", "Mustafa", "Aktas");
	program.createUser("kubboz", "Kubilay", "Bozok");
	program.createUser("afghan", "Naim", "Nazar");
	program.createUser("fake", "Unknown", "Person");
	program.createUser("duvakli", "Selim", "Duvakli");
	program.createUser("stranger", "Phil", "Baker");

	//All Users
	cout << "ALL USERS:"<<endl << endl;
	program.printAllUsers();


	//Videos
	program.createVideo("GTA V", "gaming");
	program.createVideo("LOL", "gaming");
	program.createVideo("Real Madrid vs Bercelona", "football");
	program.createVideo("How to make a Robot that speak with us", "robotics");
	program.createVideo("Visiting London", "documentery");
	program.createVideo("Eurovision Sertap Erener", "music");

	//All Videos
	cout << "ALL VIDEOS:" << endl << endl;
	program.printAllVideos();
	
	//Add Friendship
	program.addFriendship("mrtckmk", "mstakts");	//mutual friendship
	program.addFriendship("mrtckmk", "afghan");
	program.addFriendship("mrtckmk", "fake");
	program.addFriendship("mstakts", "kubboz");
	program.addFriendship("kubboz", "duvakli");
	program.addFriendship("kubboz", "mrtckmk");

	//User not found error
	cout << "ERROR MESSAGE!" << endl << endl;
	program.addFriendship("apple", "mrtckmk");

	//Update Status
	program.updateUserStatus("duvakli", SUSPENDED);

	//Friends of User
	cout << "FRIEND OF THE USER:"<<endl;
	program.printFriendsOfUser("mrtckmk");
	program.printFriendsOfUser("kubboz");
	program.printFriendsOfUser("mstakts");

	//Remove Friendship
	cout << "AFTER REMOVE FRIENDSHIP:" << endl << endl;
	program.removeFriendship("mrtckmk", "fake");

	program.printFriendsOfUser("mrtckmk");

	//Delete User
	cout<<"AFTER DELETE USER:"<< endl << endl;
	program.deleteUser("fake");
	program.printAllUsers();

	//Subscribe to videos
	program.subscribe("mrtckmk", "GTA V");
	program.subscribe("mrtckmk", "How to make a Robot that speak with us");
	program.subscribe("mstakts", "Visiting London");
	program.subscribe("mstakts", "How to make a Robot that speak with us");
	program.subscribe("kubboz", "Real Madrid vs Bercelona");
	program.subscribe("kubboz", "LOL");

	//Suspended Error
	cout << "ERROR MESSAGE!" << endl << endl;
	program.subscribe("duvakli", "Eurovision Sertap Erener");


	//Video not found error
	cout << "ERROR MESSAGE!" << endl << endl;
	program.subscribe("mstakts", "Probability Lectures");

	//User Subscriptions
	cout << "USER SUBSCRIPTIONS:"<<endl<<endl;
	program.printUserSubscriptions("mrtckmk");

	//After Unsubscribe
	cout << "AFTER UNSUBSCRIBE:" << endl << endl;
	program.unSubscribe("kubboz", "LOL");
	program.printUserSubscriptions("kubboz");

	//Friend Subscriptions
	cout << "FRIEND SUBSCRIPTIONS:" << endl << endl;
	program.printFriendSubscriptions("kubboz");		//distinct subscriptions

	//Common Subscriptions
	cout << "COMMON SUBSCRIPTIONS:" << endl << endl;
	program.printCommonSubscriptions("mstakts", "mrtckmk");
	
	//Friends or friends of a friend
	cout << "FRIENDS OR FRIENDS OF A FRIEND:" << endl << endl;
	program.isFriendOfFriend("mrtckmk", "duvakli");
	program.isFriendOfFriend("kubboz", "mstakts");
	program.isFriendOfFriend("mstakts", "stranger");

	return 0;
}