#include "VideoShare.h"

VideoShare::VideoShare(){}

VideoShare::~VideoShare(){}

void VideoShare::createUser(const string & userName, const string & name, const string & surname)
{
	User new_user(userName, name, surname);
	users.insertNode(users.getHead(), new_user);
}
void VideoShare::loadUsers(const string & fileName)
{

}
void VideoShare::createVideo(const string & title, const string & genre)
{
	Video new_video(title, genre);
	videos.insertNode(videos.getHead(), new_video);
}

void VideoShare::loadVideos(const string & fileName)
{

}

void VideoShare::addFriendship(const string & userName1, const string & userName2) {

	if (checkUser(userName1) && checkUser(userName2))
	{
		User* user1 = users.findNode(userName1)->getDataPtr();
		User* user2 = users.findNode(userName2)->getDataPtr();

		user1->addFriend(user2);
		user2->addFriend(user1);
	}
	else cout << "The program could not add friendship!"<<endl << endl;
}

void VideoShare::removeFriendship(const string & userName1, const string & userName2)
{
	if (checkUser(userName1) && checkUser(userName2))
	{
		User* user1 = users.findNode(userName1)->getDataPtr();
		User* user2 = users.findNode(userName2)->getDataPtr();
		user1->removeFriend(user2);
		user2->removeFriend(user1);
	}
	else cout << "The program could not remove friendship!"<<endl << endl;
}

void VideoShare::updateUserStatus(const string & userName, Status newStatus)
{
	if (checkUser(userName))
	{
		User* user = users.findNode(userName)->getDataPtr();
		user->updateStatus(newStatus);
	}
	else cout << "The program could not update status of the user!" << endl << endl;
}

void VideoShare::subscribe(const string & userName, const string & videoTitle)
{
	if (checkUser(userName) && checkVideo(videoTitle))
	{
		User* user = users.findNode(userName)->getDataPtr();
		Video* video = videos.findNode(videoTitle)->getDataPtr();
		
		if (user->getStatus() == ACTIVE)
		{
			user->subscribe(video);
		}
		else cout << "Suspended user can not subscribe!" << endl << endl;
	}
	else cout << "The program could not do subscribe processes!" << endl << endl;
}

void VideoShare::unSubscribe(const string & userName, const string & videoTitle)
{

	if (checkUser(userName) && checkVideo(videoTitle))
	{
		User* user = users.findNode(userName)->getDataPtr();
		Video* video = videos.findNode(videoTitle)->getDataPtr();

		if (user->getStatus() == ACTIVE)
		{
			user->unSubscribe(video);
		}
		else cout << "Suspended user can not unsubscribe!" << endl << endl;
	}
	else cout << "The program could not do unsubscribe processes!" << endl << endl;
}

void VideoShare::deleteUser(const string & userName)
{
	if (checkUser(userName))
	{
		User* user = users.findNode(userName)->getDataPtr();
		Node<User*>* temp = user->getFriends()->first();

		while (temp != NULL)
		{
			temp->getData()->removeFriend(user);	// removes the user from the friend of the user.
			temp = temp->getNext();
		}
		users.deleteNode(users.findPrev(userName));
	}
	else cout << "The program could not delete the user!" << endl << endl;
}

void VideoShare::printAllUsers()
{
	users.print();
}

void VideoShare::printAllVideos()
{
	videos.print();
}

void VideoShare::printUserSubscriptions(const string & userName)
{
	if (checkUser(userName))
	{
		User* user = users.findNode(userName)->getDataPtr();
		user->printSubscriptions(userName);
	}
	else cout << "The program could not print the user subscriptions!" << endl << endl;
}

void VideoShare::printFriendsOfUser(const string & userName)
{
	if (checkUser(userName))
	{
		User* user = users.findNode(userName)->getDataPtr();
		user->printFriends(userName);
	}
	else cout << "The program could not print the friend of the user!" << endl << endl;
	
}

void VideoShare::printCommonSubscriptions(const string & userName1, const string & userName2)
{
	if (checkUser(userName1) && checkUser(userName2))
	{
		cout << userName1 << " and " << userName2 << " common subscriptions:" << endl << endl;
		User* user1 = users.findNode(userName1)->getDataPtr();
		User* user2 = users.findNode(userName2)->getDataPtr();

		Node<Video*>* temp1 = user1->getSubscriptions()->first();
		Node<Video*>* temp2 = user2->getSubscriptions()->first();
		while (temp1 != NULL)
		{
			temp2 = user2->getSubscriptions()->first();
			while (temp2 != NULL)
			{
				if (temp1->getData() == temp2->getData())
				{
					cout << *temp1->getData()<< endl << endl;
				}
				temp2 = temp2->getNext();
			}
			temp1 = temp1->getNext();
		}
	}
	else cout << "The program could not print the common subscriptions of the users!" << endl << endl;
}

void VideoShare::printFriendSubscriptions(const string & userName)
{
	if (checkUser(userName))
	{
		User* user = users.findNode(userName)->getDataPtr();
		Node<User*>* temp = user->getFriends()->first();
		Node<Video*>* temp2 = temp->getData()->getSubscriptions()->first();
		LinkedList<Video> distinct;

		while (temp != NULL)
		{
			temp2 = temp->getData()->getSubscriptions()->first();
			while (temp2 != NULL)
			{
				if (distinct.findNode(*(temp2->getData())) == NULL)					// if given title is distinct or not found in the list
				{
					distinct.insertNode(distinct.getHead(), *(temp2->getData()));
				}
				temp2 = temp2->getNext();
			}
			temp = temp->getNext();
		}
		cout << userName << "'s Friend Subscriptions:" << endl << endl;
		distinct.print();
	}
	else cout << "The program could not print the friend subscriptions of the user!" << endl << endl;
}

bool VideoShare::isFriendOfFriend(const string & userName1, const string & userName2)
{
	if (checkUser(userName1) && checkUser(userName2))
	{
		User* user1 = users.findNode(userName1)->getDataPtr();
		User* user2 = users.findNode(userName2)->getDataPtr();

		Node<User*>* temp1 = user1->getFriends()->first();
		Node<User*>* temp2 = user2->getFriends()->first();

		while (temp1 != NULL)
		{
			temp2 = user2->getFriends()->first();
			while (temp2 != NULL)
			{
				if (temp1->getData() == temp2->getData())
				{
					cout << userName1 << " and " << userName2 << " are friends or they are friends of a friend." << endl << endl;
					return true;
				}
				temp2 = temp2->getNext();
			}
			temp1 = temp1->getNext();
		}
		cout << userName1 << " and " << userName2 << " are not friends or they are not friends of a friend." << endl << endl;
		return false;
	}
	else cout << "The program could not check given users are friend of a friend!" << endl << endl;
	return false;
}

bool VideoShare::checkUser(string userName)
{
	if (users.findNode(userName) == NULL)	//If the given user is not found!
	{
		cout << "User is not found!" << endl << endl;
		return false;
	}
	else return true;
}
bool VideoShare::checkVideo(string videoTitle)
{
	if (videos.findNode(videoTitle) == NULL)	//If the given video is not found!
	{
		cout << "Video is not found!" << endl << endl;
		return false;
	}
	else return true;
}