/*
CISP 430
Circular List Implementation
@author: Prof Ross
@editor: Lawrence
@version: Feb 2018
*/
#include <iostream>
using namespace std;

// the list
const int SIZE = 10;
char myList[SIZE];
int head, tail, used;

// function declarations
char remove();
void append(char);
int find(char);
void traverse();
int isEmpty();

// main for testing functions
int main()
{
	// initialization
	head = tail = used = 0;
	
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

	// empty the list
	cout << "Removed:\n";
	while (!isEmpty())
	{
		cout << remove() << "\n";
	}
	cout << endl;
	traverse();
	
	find('G');

	return 0;
}

// receives a data element and appends it to the tail of the list
void append(char c)
{
	// if list is empty
	if (!used)
	{
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
	tail = (tail + 1) % SIZE;
	myList[tail] = c;
	used++;
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

// returns true if the list is empty, false if otherwise
int isEmpty()
{
	if (used)
		return 0;
	else
		return 1;
}

// searches the list for an element
// if data found, removes element and returns 1
// else, returns 0
int find(char c)
{
	int p; // pointer

	// empty?
	if (isEmpty())
	{
		return 0;
	}

	// only one node?
	if (used == 1)
	{
		if (myList[head] == c)
		{
			used = 0;
			cout << c << " found.\n";
			return 1;
		}
		else
		{
			cout << c << " not found.\n";
			return 0;
		}
	}

	// more than 1 element
	p = head;
	do {
		if (myList[p] == c) // found it
		{
			// scoot stuff
			while (p != tail)
			{
				myList[p] = myList[(p + 1) % SIZE];
				p = (p + 1) % SIZE;
			}
			tail--;
			if (tail < 0) tail = SIZE - 1;
			used--;
			cout << c << " found.\n";
			return 1;
		}
		p = (p + 1) % SIZE;
	} while (p != (tail + 1) % SIZE);
	cout << c << " not found.\n";
	return 0;
}

// remove a data element from the head of the list and returns it
// return -1 if the list is empty
char remove()
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