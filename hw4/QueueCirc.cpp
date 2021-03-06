/*
CISP 430
Queue Circular List Implementation
@author: Lawrence
@version: Feb 2018
*/
#include <iostream>
using namespace std;

// the list
const int SIZE = 10;
char myList[SIZE];
int head, tail, used;

// function declarations
void q(char);		// appends data to the tail of the list
char dq();			// removes the head node and returns data; returns -1 if empty
bool isEmpty();		// returns true if queue is empty, false if otherwise
void traverse();	// traverses the list from head to tail and prints out each data element

// main for testing functions
int main()
{
	// initialization
	head = tail = used = 0;

	q('A');
	q('B');
	cout << "dq: " << dq() << "\n";
	q('C');
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
	// if list is empty
	if (isEmpty())
	{
		cout << "q: " << c << "\n";
		myList[tail] = c;
		used++;
		return;
	}

	// prevent overflow
	if ((tail + 1) % SIZE == head)
	{
		cout << "Overflow. Element not appended.\n";
		return;
	}

	// append data
	cout << "q: " << c << "\n";
	tail = (tail + 1) % SIZE;
	myList[tail] = c;
	used++;
}

// removes the head node and returns data; returns -1 if empty
char dq()
{
	char temp;

	// empty list
	if (isEmpty())
	{
		return -1;
	}

	// 1 element
	if (used == 1)
	{
		used = 0;
		return myList[head];
	}

	// more than 1 element
	// remove data
	temp = myList[head];
	head = (head + 1) % SIZE;
	used--;
	return temp;
}

// traverses the list from head to tail and prints out each data element
void traverse()
{
	char p;

	// empty list
	if (isEmpty())
	{
		cout << "The list is empty.\n";
		return;
	}

	// 1 element
	if (used == 1)
	{
		cout << "The list contains:\n" << myList[head] << endl;
		return;
	}

	// more than 1 element
	p = head;
	cout << "The list contains:\n";
	do {
		cout << myList[p] << "\n";
		p = (p + 1) % SIZE;
	} while (p != (tail + 1) % SIZE);
	cout << endl;
}

// returns true if queue is empty, false if otherwise
bool isEmpty()
{
	if (used)
		return false;
	else
		return true;
}