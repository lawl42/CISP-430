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
char remove();
void append(char);
int find(char);
void traverse();
int isEmpty();

// main for testing access functions
int main()
{
	append('A');
	append('B');
	append('C');
	append('D');
	append('E');
	append('F');
	traverse();

	find('X');
	find('D');
	traverse();

	cout << "Removed: " << remove() << "\n";
	cout << "Removed: " << remove() << "\n";
	traverse();

	// empty the list
	cout << "Removed:\n";
	while (!isEmpty())
		cout << remove() << "\n";
	cout << endl;
	traverse();

	find('G');

	return 0;
}

// receives a char element and appends it to the tail of the list
void append(char c)
{
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
int isEmpty()
{
	if (head)
		return 0;
	else
		return 1;
}

// removes a char element from the head of the list and returns it
// returns -1 if the list is empty
char remove()
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

// searches the list for a char element
// if the char is found, removes the char element and returns 1, otherwise, returns 0
int find(char d)
{
	node * c;
	node * pc;

	// empty
	if (!head)
	{
		cout << d << " not found.\n";
		return 0;
	}

	// only one node
	if (head == tail)
	{
		if (head->d == d)
		{
			// destroy node
			delete head;
			head = tail = 0;
			cout << d << " found.\n";
			return 1;
		}
		else
		{
			cout << d << " not found.\n";
			return 0;
		}
	}

	// two or more nodes
	pc = head;
	c = head->next;
	if (pc->d == d) // found at head
	{
		head = head->next;
		delete pc;
		cout << d << " found.\n";
		return 1;
	}

	// look at nodes after head
	while (c)
	{
		if (c->d == d)
		{
			pc->next = c->next;
			if (c == tail)
				tail = pc;
			// destroy node
			delete c;
			cout << d << " found.\n";
			return 1;
		}
		pc = c;
		c = c->next;
	}
	cout << d << " not found.\n";
	return 0;
}