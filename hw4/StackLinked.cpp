/*
@author: Lawrence
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
void push(char);
char pop();
char peek();
bool isEmpty();

// main for testing access functions
int main()
{
	push('A');
	cout << "PEEK: " << peek() << "\n";
	push('B');
	cout << "POP: " << pop() << "\n";
	push('C');
	cout << "PEEK: " << peek() << "\n";
	push('D');
	cout << "POP: " << pop() << "\n";
	cout << "POP: " << pop() << "\n";
	push('E');
	push('F');
	traverse();

	// empty the list
	cout << "Removed:\n";
	while (!isEmpty())
		cout << pop() << "\n";
	cout << endl;
	traverse();

	return 0;
}

// appends data to the head of the list
void push(char c)
{
	cout << "PUSH: " << c << "\n";

	// make a new node
	node * p = new node;
	p->next = head;
	p->d = c;

	if (!head) // list is empty
	{
		head = tail = p;
	}
	else
	{
		head = p;
	}
}

// traverses the list from the head to the tail and prints out each char element
void traverse()
{
	node * p = head;

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
char pop()
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

//returns a copy of data at the head but does not remove the head; returns –1 if empty
char peek()
{
	// empty?
	if (isEmpty())
		return -1;

	return head->d;
}
