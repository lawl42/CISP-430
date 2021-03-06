/*
CISP 430
Priority Queue Circular List Implementation
@author: Lawrence
@version: Feb 2018
*/
#include <iostream>
using namespace std;

// dat
class dat
{
public:
	char e;
	int p;
	
public:
	dat(char e = '*', int p = -1)
	{
		this->e = e;
		this->p = p;
	}

};

// the list
const int SIZE = 10;
dat myList[SIZE];
int head, tail, used;

// function declarations
void insert(dat);	// inserts data in sorted order 
dat dq();			// removes the head node and returns data; returns –1 if empty
dat peek();			// returns a copy of data at the head but does not remove the head; returns –1 if empty 
bool isEmpty(void); // returns true if the Pqueue is empty, returns false otherwise
void traverse();

// main for testing functions
int main()
{
	// initialization
	head = tail = used = 0;

	insert(dat('A', 84));
	insert(dat('B', 77));
	insert(dat('C', 8));
	cout << "Peek: " << peek().e << ", " << peek().p << "\n\n";
	insert(dat('D', 89));
	insert(dat('E', 25));
	insert(dat('F', 54));
	cout << "Peek: " << peek().e << ", " << peek().p << "\n\n";
	traverse();

	// empty the list
	cout << "dq:\n";
	while (!isEmpty())
	{
		dat temp = dq();
		cout << temp.e << ", " << temp.p << "\n";
	}

	cout << endl;
	traverse();

	return 0;
}

// receives a data element and appends it to the tail of the list
void insert(dat c)
{
	// prevent overflow
	if ((tail + 1) % SIZE == head)
	{
		cout << "Overflow. Element not appended.\n";
		return;
	}

	cout << "q: " << c.e << ", " << c.p << "\n";

	// if list is empty
	if (!used)
	{
		myList[tail] = c;
		used++;
		return;
	}

	// append data
	tail = (tail + 1) % SIZE;
	used++;

	// highest priority
	if (c.p > myList[head].p)
	{
		dat temp;
		for (int i = head; i <= tail; i++)
		{
			temp = myList[i];
			myList[i] = c;
			c = temp;
		}
		return;
	}

	// lowest priority
	if (c.p < myList[tail - 1].p)
	{
		myList[tail] = c;
		return;
	}

	// append data
	for (int i = head + 1; i < tail; i++)
	{
		if (c.p >= myList[i].p && c.p <= myList[i - 1].p)
		{
			dat temp;
			for (int j = i; j <= tail; j++)
			{
				temp = myList[j];
				myList[j] = c;
				c = temp;
			}
		}
	}
}

// traverses the list from head to tail and prints out each data element
void traverse()
{
	int p;

	// empty list
	if (isEmpty())
	{
		cout << "The list is empty.\n";
		return;
	}

	// 1 element
	if (used == 1)
	{
		cout << "The list contains:\n" << myList[head].e << ", " << myList[head].p << "\n\n";
		return;
	}

	// more than 1 element
	p = head;
	cout << "The list contains:\n";
	do {
		cout << myList[p].e << ", " << myList[p].p << "\n";
		p = (p + 1) % SIZE;
	} while (p != (tail + 1) % SIZE);
	cout << "\n";
}

// returns true if the list is empty, false if otherwise
bool isEmpty()
{
	if (used)
		return false;
	else
		return true;
}

// remove a data element from the head of the list and returns it
// return -1 if the list is empty
dat dq()
{
	dat temp;

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
dat peek()
{
	if (isEmpty())
		return -1;
	return myList[head];
}