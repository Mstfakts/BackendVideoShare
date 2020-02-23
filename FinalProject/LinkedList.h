#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T> class LinkedList {
private:
	Node<T>* head;
	int length;

public:
	LinkedList();											
	~LinkedList();											
	Node<T>* getHead() const;						// To get the head which points to the first node.
	Node<T>* first() const;                         // To get the first node from the SLL
	Node<T>* findPrev(const T& data) const;         // To get the previous node from given data
	Node<T>* findNode(const T& data) const;         // To ge the node by giving the data
	void insertNode(Node<T>* prev, const T& data);  // To insert a node after another node.
	void deleteNode(Node<T>* prevNode);             // To delete a node by giving the previous node
	int getLength() const;                          // To get the length of the SLL
	void print() const;                             // To display the SLL
};

template <typename T> LinkedList<T>::LinkedList() {
	//----------------------------------
	// This method is default constructor.
	//
	// Creates only head, which will
	// point to the first node.
	//----------------------------------
	head = new Node<T>(T());
	length = 0;
}

template <typename T>Node<T>* LinkedList<T>::getHead()const {
	//----------------------------------
	// This method returns the head of Single Linked List.
	//
	// Parameteres: 
	//
	// Return: (Node<T>*) head: The head which points to the
	//			first node of SLL. The const indicates that
	//			the value which is returned by this method
	//			cannot be changed.
	//----------------------------------
	return head;
}

template <typename T>Node<T>* LinkedList<T>::first()const {
	//----------------------------------
	// This method returns the first node of Single Linked List.
	//
	// Parameteres: 
	//
	// Return: (Node<T>*) head->getNext(): The first node of the SLL.
	//			The head was pointing the first node of SLL. So, I just
	//			returned the heaad->getNext() which holds the first node.
	//			The const indicates that the value which is returned by 
	//			this method cannot be changed.		
	//----------------------------------
	return head->getNext();
}

template <typename T>Node<T>* LinkedList<T>::findPrev(const T& data) const {
	//----------------------------------
	// This method returns the previous node of given data in the SLL.
	//So, we first need to find the node that contain of the given data.
	//
	// Parameteres: (const T&) data: The data address that we want to return
	//				previous of it. const indicates that its forbidden to change
	//				the value of data. So, the data is protected to change.
	//				The const indicates that the value which is returned by 
	//				this method cannot be changed.
	//
	// Return: (Node<T>*) prev: The previous node of the given data.
	//					  NULL: If the given data cannot be found in SLL.
	//					  The const indicates that the value which is returned by 
	//					  this method cannot be changed.	
	//----------------------------------

	Node<T> *temp = getHead(); // *temp for moving on the SLL.
	Node<T> *prev; 			   // *prev holds the previous node.

	while (temp->getNext() != NULL) { // Go through the SLL.
		prev = temp; //Firstly hold the node, and check the second after node.
		if (temp->getNext()->getData() == data)
			return prev;
		temp = temp->getNext();
	}
	return NULL;
}

template <typename T>Node<T>* LinkedList<T>::findNode(const T& data) const {
	//----------------------------------
	// This method returns the node of the given data.
	//
	// Parameteres: (const T&) data: The data address that we want to find
	//				in the SLL. const indicates that its forbidden to change
	//				the value of data. So, the data is protected to change.
	//
	// Return: (Node<T>*) temp: The node that contains the given data.
	//					  NULL: If the given data cannot be found in SLL.
	//					  The const indicates that the value which is returned by 
	//					  this method cannot be changed.
	//----------------------------------
	Node<T> *temp = first(); // *temp for moving on the SLL.
	while (temp) { // Go through the SLL.
		if (temp->getData() == data) // If the node includes given data 
			return temp;			// return that node.
		temp = temp->getNext();
	}
	return NULL;
}

template <typename T> void LinkedList<T>::insertNode(Node<T>* prev, const T & data) {
	//----------------------------------
	// This method insert a node in to the SLL.
	//
	// Parameteres: (Node<T>*) prev: the node that we will insert a new node
	//				after it.
	//
	//				(const T&) data: The data address that we want to insert
	//				in to the SLL. const indicates that its forbidden to change
	//				the value of data. So, the data is protected to change.
	//
	// Return: void
	//----------------------------------

	if (prev) { // Check if the given node is exist.
		Node<T>* newNode = new Node<T>(data); // Create new node
		newNode->setNext(prev->getNext()); // New node will point to the next node of prev.
		prev->setNext(newNode); // prev node will point to the node that just inserted.
		length++; // Increment the length.
	}
}

template <typename T> void LinkedList<T>::deleteNode(Node<T>* prevNode) {
	//----------------------------------
	// This method deletes a node from the SLL.
	//
	// Parameteres: (Node<T>*) prev: the previous node that we will delete.
	//
	// Return: void
	//----------------------------------
	if (prevNode) {
		if (prevNode->getNext()) { // Check if the given node is exist.
			// prev node will point to the second next of it.
			// It is like skipping the one node.
			prevNode->setNext(prevNode->getNext()->getNext());
			length--; //Decrease the length.
		}
	}

}

template <typename T>int LinkedList<T>::getLength()const {
	//----------------------------------
	// This method returns the length of the SLL.
	//
	// Parameteres: 
	//
	// Return: (int) length: The length of the SLL.
	//					  NULL: If the given data cannot be found in SLL.
	//					  The const indicates that the value which is returned by 
	//					  this method cannot be changed.
	//----------------------------------
	return length;
}

template <typename T>void LinkedList<T>::print()const {
	//----------------------------------
	// This method prints the SLL.
	//
	// Parameteres: 
	//
	// Return: void
	//----------------------------------
	Node<T>* temp = first(); // *temp for moving on the SLL.
	while (temp) {
		cout << temp->getData()<<endl;
		temp = temp->getNext();
	}
	cout << endl;
}

template <typename T>LinkedList<T>::~LinkedList() {
	//----------------------------------
	// Default destructor
	//----------------------------------
}

#endif
