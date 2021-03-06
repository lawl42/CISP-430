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
	char d;
};

// head and tail pointers
node * head = 0;
node * tail = 0;

// function declarations
void traverse();
void q(char);
char dq();
bool isEmpty();

// main for testing access functions
int main()
{
	q('A');
	q('B');
	q('C');
	cout << "dq: " << dq() << "\n";
	q('D');
	q('E');
	cout << "dq: " << dq() << "\n";
	q('F');
	traverse();

	// empty the list
	cout << "Removed:\n";
	while (!isEmpty())
		cout << dq() << "\n";
	cout << endl;
	traverse();

	return 0;
}

// appends data to the tail of the list
void q(char c)
{
	cout << "q: " << c << "\n";

	// make a new node
	node * p = new node;
	p->next = 0;
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

// traverses the list from the head to the tail and prints out each char element
void traverse()
{
	node * p = head;

	if (!p)
	{
		cout << "The list is empty.\n";
		return;
	}

	cout << "The list contains:\n";
	while (p)
	{
		cout << (char)p->d << " ";
		p = p->next;
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

// removes the head node and returns data; returns –1 if empty
char dq()
{
	node * p;
	char temp;

	// return null if the list is empty
	if (!head)
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
