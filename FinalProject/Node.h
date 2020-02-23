#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T> class Node {
private:
	Node<T> *next;
	T data;

public:
	Node();
	Node(const T &d);
	Node<T> *getNext() const;       // To get the next node from another node
	T getData() const;              // To get data of given node
	T *getDataPtr();                // To get dddress of the data
	void setNext(Node<T> *newNext); // To set the pointer to point given node.
};

template <typename T> Node<T> ::Node() {
	//----------------------------------
	// This method is default constructor.
	//
	// Assigns the pointer to NULL, and create
	// data object in the type of T
	//----------------------------------
	next = NULL;
	data = T();
}

template <typename T> Node <T> ::Node(const T &d) {
	//----------------------------------
	// This method is one parameter constructor.
	//
	// Parameteres: (const T&) data: The data address that we want to keep.
	//----------------------------------
	next = NULL;
	data = d;
}

template <typename T> Node <T>* Node <T> ::getNext() const {
	//----------------------------------
	// This method returns the pointer that points to the next node.
	//
	// Parameteres: -
	//
	// Return: (Node<T>*) next: The node that was pointed.
	//----------------------------------
	return next;
}

template <typename T> T Node <T> ::getData() const {
	//----------------------------------
	// This method returns the data of given node.
	//
	// Parameteres: -
	//
	// Return: (T) data: Data of a node
	//----------------------------------
	return data;
}

template <typename T> T* Node<T>::getDataPtr(){
	//----------------------------------
	// This method returns the address of the data.
	//
	// Parameteres: -
	//
	// Return: (T*) &data: Addree of the data of a node
	//----------------------------------
	return &data;
}

template <typename T> void Node<T> ::setNext(Node<T> *newNext) {
	//----------------------------------
	// This method assign the pointer to point a node.
	//
	// Parameteres: (Node<T>*) newNext: The address of the node
	//
	// Return: -
	//----------------------------------
	next = newNext;
}
#endif
