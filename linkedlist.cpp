#include "linkedlist.h"

// default constructor
LinkedList::LinkedList()
: head(nullptr), tail(nullptr) 
{ }

// copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
	Node* temp;
	temp = rhs.head;

	while (temp != nullptr)
	{
		this->addToEnd(temp->value);
		temp = temp->next;
	}
}

// Destroys all the dynamically allocated memory
// in the list.
LinkedList::~LinkedList()
{
	Node* temp = head;
	Node *forward;

	while (temp != nullptr)
	{
		forward = temp->next; // remember what next node we will delete.
		delete temp;
		temp = forward; // move temp to next node
	}

	head = nullptr;
	tail = nullptr;
}

// assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	Node* temp = head;
	Node* forward = nullptr;

	while (temp != nullptr) // clear memory of target variable
	{
		forward = temp->next;
		delete temp;
		temp = forward;
	}

	head = nullptr;
	tail = nullptr;

	if (rhs.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}

	else
	{		
		temp = rhs.head;
		
		while (temp != nullptr)
		{
			this->addToEnd(temp->value);
			temp = temp->next;
		}
	}

	return *this;
}

// Inserts val at the front of the list
void LinkedList::insertToFront(const ItemType& val)
{
	Node *temp = new Node;
	temp->value = val;
	
	if (head == nullptr) // if list is empty, this is the only node. set head and tail to temp.
	{
		temp->next = nullptr;
		temp->prev = nullptr;
		head = temp;
		tail = temp;
	}
	else  // otherwise, insert node at front of list and re-assign head ptr.
	{
		temp->next = head; 
		temp->prev = nullptr; 
		head->prev = temp;
		head = temp;
	}
}

// Returns the number of items in the Linked List.
int LinkedList::size() const
{
	int i = 0;

	Node *temp = head;

	while (temp != nullptr)
	{
		i++;
		temp = temp->next;
	}

	return i;
}

// Prints the LinkedList
void LinkedList::printList() const 
{
	Node *temp = head;

	while (temp != nullptr)
	{
		cout << temp->value;
		cout << " ";
		temp = temp->next;
	}

	cout << endl;
}

// Sets item to the value at position i in this
// LinkedList and return true, returns false if 
// there is no element i
bool LinkedList::get(int i, ItemType& item) const
{
	if (this->size() <= i)
		return false;
	else
	{
		Node *temp = head;

		for (int j = 0; j < i; j++)
		{
			temp = temp->next;
		}

		item = temp->value;

		return true;
	}
}

// Reverses the LinkedList
void LinkedList::reverseList()
{
	if (this->size() <= 1) //do nothing if empty list or only one node
		return;
	
	Node* temp = nullptr;
	Node* curr = head;
	
	while (curr != nullptr) //switch previous and next ptrs for all nodes
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}

	Node* switch_ends = head; //switch head and tail pointers.
	head = tail;
	tail = switch_ends;
}

// Prints the LinkedList in reverse order
void LinkedList::printReverse() const
{
	Node *temp = tail;
	
	while (temp != nullptr)
	{
		cout << temp->value;
		cout << " ";
		temp = temp->prev;
	}

	cout << endl;
}

void LinkedList::addToEnd(const ItemType& val) 
{
	Node* temp = new Node;
	temp->value = val;

	if (this->head == nullptr)
	{
		head = temp; // make new node head if list is empty
		head->next = nullptr;
		head->prev = nullptr;
		tail = temp;
	}
	
	else
	{
		temp->prev = tail; // otherwise point current tail towards temp
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}

	return;
}

// Appends the values of other onto the end of this LinkedList.
void LinkedList::append(const LinkedList &other)
{
	Node* temp; // took out "= new Node"
	temp = other.head;

	while (temp != nullptr)
	{
		this->addToEnd(temp->value);
		temp = temp->next;
	}
}


// Exchange the contents of this LinkedList with the other
// one.
void LinkedList::swap(LinkedList &other)
{
	LinkedList copy; //create empty linked list and store other lists in them
	copy.append(other);
	LinkedList copy2;
	copy2.append(*this);
	
	Node* temp = head;
	Node* temp2 = other.head;

	Node* forward = nullptr;
	Node* forward2 = nullptr;

	while (temp != nullptr)
	{
		forward = temp->next; // remember what next node we will delete.
		delete temp;
		temp = forward; // move temp to next node
	}

	head = nullptr;
	tail = nullptr;

	while (temp2 != nullptr)
	{
		forward2 = temp2->next; // remember what next node we will delete.
		delete temp2;
		temp2 = forward2; // move temp to next node
	}

	other.head = nullptr;
	other.tail = nullptr;

	other.append(copy2);
	this->append(copy);

	return;
}