/*
CISP 430
Linked List Implementation
@author: Prof Ross
@editor: Lawrence
@version: Feb 2018
*/

#include <iostream>
using namespace std;

// node
struct node
{
	node * next;
	node * prev;
	char d;
};

// head and tail pointers
node * head = 0;
node * tail = 0;

// function declarations
void appendTail(char);	// appends data to the tail of the list
void appendHead(char);	// appends data to the head of the list
char removeTail();		// removes the tail node and returns data; returns -1 if the list is empty
char removeHead();		// removes the head node and returns data; returns –1 if the list is empty
void traverseFWD();		// traverses the list from the head to the tail, and prints out each data element
void traverseBWD();		// traverses the list from the tail to the head, and prints out each data element
bool isEmpty();			// returns true if the list is empty, returns false otherwise

// main for testing access functions
int main()
{
	appendTail('A');
	appendHead('B');
	appendTail('C');
	cout << "removeT: " << removeTail() << "\n";
	appendTail('D');
	appendHead('E');
	cout << "removeH: " << removeHead() << "\n";
	appendHead('F');
	traverseFWD();
	traverseBWD();

	return 0;
}

// appends data to the tail of the list
void appendTail(char c)
{
	cout << "appendT: " << c << "\n";

	// make a new node
	node * p = new node;
	p->next = 0;
	p->prev = tail;
	p->d = c;

	if (!head) // list is empty
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

// appends data to the head of the list
void appendHead(char c)
{
	cout << "appendH: " << c << "\n";

	// make a new node
	node * p = new node;
	p->next = head;
	p->prev = 0;
	p->d = c;

	if (!head) // list is empty
	{
		head = tail = p;
	}
	else
	{
		head->prev = p;
		head = p;
	}
}

// removes the tail node and returns data; returns –1 if the list is empty
char removeTail()
{
	node * p;
	char temp;

	// return null if the list is empty
	if (isEmpty())
		return -1;

	// only one node?
	if (head == tail)
	{
		// remove and destroy tail node
		temp = tail->d;
		delete tail;
		head = tail = 0;
		return temp;
	}

	// more than one node
	// remove and destroy head node
	p = tail;
	tail = tail->prev;
	temp = p->d;
	delete p;
	return temp;
}

// removes the head node and returns data; returns –1 if empty
char removeHead()
{
	node * p;
	char temp;

	// return null if the list is empty
	if (isEmpty())
		return -1;

	// only one node?
	if (head == tail)
	{
		// remove and destroy head node
		temp = head->d;
		delete head;
		head = tail = 0;
		return temp;
	}

	// more than one node
	// remove and destroy head node
	p = head;
	head = head->next;
	temp = p->d;
	delete p;
	return temp;
}

// traverses the list from the head to the tail and prints out each char element
void traverseFWD()
{
	node * p = head;

	cout << "Traverse FWD:\n";
	while (p)
	{
		cout << (char)p->d << " ";
		p = p->next;
	} 
	cout << endl;
}

// traverses the list from the head to the tail and prints out each char element
void traverseBWD()
{
	node * p = tail;

	cout << "Traverse BWD:\n";
	while (p)
	{
		cout << (char)p->d << " ";
		p = p->prev;
	} 
	cout << endl;
}

// returns true if the list is empty, false if otherwise
bool isEmpty()
{
	if (head)
		return false;
	else
		return true;
}

