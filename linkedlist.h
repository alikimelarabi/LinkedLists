#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

typedef string ItemType;

struct Node
{
	ItemType value;
	Node* next;
	Node* prev;
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	// adds ItemType (by reference) to end of LinkedList
	void addToEnd(const ItemType& val);

public:
	// default constructor
	LinkedList(); // assigns nullptr to head to create empty list
										 
	LinkedList(const LinkedList& rhs); // copy constructor

	// Destroys all the dynamically allocated memory
	// in the list.
	~LinkedList();

	// assignment operator
	const LinkedList& operator=(const LinkedList& rhs);

	// Inserts val at the front of the list
	void insertToFront(const ItemType& val);
	
	// Prints the LinkedList
	void printList() const;

	// Sets item to the value at position i in this
	// LinkedList and return true, returns false if 
	// there is no element i
	bool get(int i, ItemType& item) const;

	// Reverses the LinkedList
	void reverseList();

	// Prints the LinkedList in reverse order
	void printReverse() const;

	// Appends the values of other onto the end of this
	// LinkedList.
	void append(const LinkedList &other);

	// Exchange the contents of this LinkedList with the other
	// one.
	void swap(LinkedList &other);

	// Returns the number of items in the Linked List.
	int size() const;
};

#endif
