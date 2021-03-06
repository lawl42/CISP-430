/*
CISP 430
Linked List Implementation
@author: Prof Ross
@editor: Lawrence
@version: Feb 2018
*/

#include <iostream>
using namespace std;

// class dat
class dat
{
public:
	dat * next;
	char d;
	int p;

public:
	dat(char d = '*', int p = -1)
	{
		this->d = d;
		this->p = p;
	}
};

// head and tail pointers
dat * head = 0;
dat * tail = 0;

// function declarations
void traverse();
void insert(dat);	// inserts data in sorted order
dat dq(void);		// removes the head node and returns data; returns –1 if empty
dat peek(void);		// returns a copy of data at the head but does not remove the head; returns –1 if empty
bool isEmpty(void); // returns true if the Pqueue is empty, returns false otherwise

// main for testing access functions
int main()
{
	insert(dat('A', 84));
	insert(dat('B', 77));
	insert(dat('C', 8));
	cout << "Peek: " << peek().d << ", " << peek().p << "\n\n";
	insert(dat('D', 89));
	insert(dat('E', 25));
	insert(dat('F', 54));
	cout << "Peek: " << peek().d << ", " << peek().p << "\n\n";
	traverse();
	
	// empty the list
	cout << "dq:\n";
	while (!isEmpty())
	{
		dat temp = dq();
		cout << temp.d << ", " << temp.p << "\n";
	}
	cout << endl;
	traverse();

	return 0;
}

// receives a char element and appends it to the tail of the list
void insert(dat c)
{
	cout << "insert: " << c.d << ", " << c.p << "\n";

	// make a new node
	dat * p = new dat;
	p->next = 0;
	p->d = c.d;
	p->p = c.p;

	if (isEmpty()) // list is empty
	{
		head = tail = p;
		return;
	}
	
	// append data
	
	// highest priority
	if (c.p > head->p)
	{
		p->next = head;
		head = p;
		return;
	}

	// lowest priority
	if (c.p < tail->p)
	{
		tail->next = p;
		tail = p;
		return;
	}

	// middle priority
	dat * q = head;
	while (p->p < q->next->p)
		q = q->next;
	p->next = q->next;
	q->next = p;
}

// removes the head node and returns data; returns –1 if empty
dat dq()
{
	if (isEmpty())
		return -1;

	dat temp = *head;

	// only one node?
	if (head == tail)
	{
		// remove and destroy head node
		delete head;
		head = tail = 0;
		return temp;
	}

	// more than one node
	// remove and destroy head node
	head = head->next;
	return temp;
}

// traverses the list from the head to the tail and prints out each char element
void traverse()
{
	if (isEmpty())
	{
		cout << "The list is empty.\n";
		return;
	}
	dat * p = head;

	cout << "The list contains:\n";
	while (p)
	{
		cout << p->d << ", " << p->p << "\n";
		p = p->next;
	}
	cout << endl;
}

// returns a copy of data at the head but does not remove the head; returns –1 if empty
dat peek()
{
	if (isEmpty())
		return -1;

	return *head;
}

// returns true if the list is empty, false if otherwise
bool isEmpty()
{
	if (head)
		return false;
	else
		return true;
}