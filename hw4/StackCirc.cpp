/*
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
void push(char);
char pop();
char peek();
bool isEmpty();
void traverse();

// main for testing functions
int main()
{
	// initialization
	head = tail = used = 0;

	// add some elements
	push('A');
	push('B');
	cout << "Peek: " << peek() << "\n";
	push('C');
	push('D');
	cout << "Peek: " << peek() << "\n";
	push('E');
	cout << "Pop: " << pop() << "\n";
	push('F');
	cout << "Peek: " << peek() << "\n";
	traverse();

	// empty the list
	cout << "Removed:\n";
	while (!isEmpty())
		cout << pop() << " ";
	cout << endl;

	traverse();

	return 0;
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
		cout << myList[p] << " ";
		p = (p + 1) % SIZE;
	} while (p != (tail + 1) % SIZE);
	cout << endl;
}

// returns true if the list is empty, false if otherwise
bool isEmpty()
{
	if (used)
		return false;
	else
		return true;
}

// appends data to the head of the list
void push(char c)
{
	// if list is empty
	if (isEmpty())
	{
		cout << "Push: " << c << "\n";
		myList[head] = c;
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
	cout << "Push: " << c << "\n";
	tail = (tail + 1) % SIZE;
	char temp;
	for (int i = head; i <= tail; i++)
	{
		temp = myList[i];
		myList[i] = c;
		c = temp;
	}
	used++;
}

// removes the head node and returns data; returns –1 if empty
char pop()
{
	char temp;

	// empty list
	if (isEmpty())
		return -1;

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

// returns a copy of data at the head but does not remove the head; returns –1 if empty
char peek()
{
	// if list is empty
	if (isEmpty())
		return -1;

	return myList[head];
}
