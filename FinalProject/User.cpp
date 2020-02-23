#include "User.h"


User::User()
{
	username = "";
	name = "";
	surname = "";
	status = ACTIVE;			//Initializing a user with active status
}

User::User(string username, string name, string surname)
{
	this->username = username;
	this->name = name;
	this->surname = surname;
	status = ACTIVE;			//Initializing a user with active status
}

User::~User() {}

const string& User::getUsername() const
{
	return username;
}

const string& User::getName() const
{
	return name;
}

const string& User::getSurname() const
{
	return surname;
}

Status User::getStatus() const
{
	return status;
}

void User::updateStatus(Status status)
{
	this->status = status;
}

//Adds the given video pointer to the beginning of the list of subscriptions.
void User::subscribe(Video *video)
{
	subscriptions.insertNode(subscriptions.getHead(), video);
}

//Deletes the video pointer from the user's subscription list
void User::unSubscribe(Video *video)
{
	subscriptions.deleteNode(subscriptions.findPrev(video));
}

//Adds the given user pointer to the beginning of the list of friends
void User::addFriend(User *user)
{
	friends.insertNode(friends.getHead(), user);
}

//Deletes the user pointer from the user's friend list
void User::removeFriend(User *user)
{
	friends.deleteNode(friends.findPrev(user));
}

//Returns the pointer of the list of subscriptions.
LinkedList<Video*>* User::getSubscriptions()
{
	return &subscriptions;
}

//Returns the pointer of the list of friends
LinkedList <User*>*User::getFriends()
{
	return &friends;
}

void User::printSubscriptions(const string &username) {
	cout << endl <<  username << "'s Video Subsriptions:"<<endl << endl;
	Node< Video*>* temp = subscriptions.first();		//start with first element
	while (temp!=NULL) {
		cout << *(temp->getData())<<endl;				//print video pointer value which is a video
		temp = temp->getNext();						
	}
	cout << endl;
}

void User::printFriends(const string &username)
{
	cout << endl << username << "'s Friends:" << endl << endl;
	Node< User*> * temp = friends.first();				//start with first element
	while (temp !=NULL) {
		cout << *(temp->getData())<<endl;				//print user pointer value which is a user
		temp = temp->getNext();
	}
	cout << endl;
}

// If the usernames are same then the users are equal.
bool User::operator==(const User &rhs) const
{
	return (rhs.getUsername() == username);
}

ostream& operator <<(ostream &out, const User &user)
{
	string stat;

	if (user.status == ACTIVE)
	{
		stat = "Active";
	}
	else stat = "Suspended";

	out << "Username: " << user.username << endl;
	out << "Name: " << user.name << endl;
	out << "Surname: " << user.surname << endl;
	out << "Status: " << stat << endl;

	return out;
}

