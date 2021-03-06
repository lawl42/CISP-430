/*
@author: Lawrence
@version: March 2018
*/

#include <iostream>
using namespace std;

// nodes to make our tree
struct node {
	int data = 0;
	node * left = NULL;
	node * right = NULL;
};
node *root = NULL;

// data to input
int arr1[] = { 1,5,4,6,7,2,3 };
int arr2[] = { 150,125,175,166,163,123,108,116,117,184,165,137,141,111,138,122,109,194,143,183,178,173,
139,126,170,190,140,188,120,195,113,104,193,181,185,198,103,182,136,115,191,144,145,155,153,151,112,129,
199,135,146,157,176,159,196,121,105,131,154,107,110,158,187,134,132,179,133,102,172,106,177,171,156,168,
161,149,124,189,167,174,147,148,197,160,130,164,152,142,162,118,186,169,127,114,192,180,101,119,128,100 };

// function declarations
void insert(int data); // creates a new node and inserts it in the correct location in the tree
void print_preorder(node *n);  // prints the data in a tree using a preorder traversal
void print_postorder(node *n);  // prints the data in a tree using a postorder traversal
void print_inorder(node *n);  // prints the data in a tree using an inorder traversal
int search(int data); // searches the tree for data. Returns 0 if data is not found, otherwise, returns the number of nodes visited 

int main()
{
	for (int i = 0; i < size(arr2); i++)
		insert(arr2[i]);
	cout << "preorder: ";
	print_preorder(root);
	cout << "\npostorder: ";
	print_postorder(root);
	cout << "\ninorder: ";
	print_inorder(root);

	cout << "\nsearch(196): " << search(196);
	cout << "\nsearch(137): " << search(137);
	cout << "\nsearch(102): " << search(102);
	cout << "\nsearch(190): " << search(190);

	cout << endl;
	return 0;
}

// creates a new node and inserts it in the correct location in the tree
void insert(int data)
{
	node *n = new node;
	n->data = data;
	node *c = root;
	node *p = root;

	// if no data yet
	if (root == NULL)
	{
		root = n;
		return;
	}

	// traverse the tree
	while (c != NULL)
	{
		p = c;
		if (n->data < c->data)
			c = c->left;
		else
			c = c->right;
	}

	// add data
	if (n->data < p->data)
		p->left = n;
	else
		p->right = n;
}

// prints the data in a tree using a preorder traversal
void print_preorder(node *n)
{
	if (n != NULL)
	{
		cout << n->data << " ";
		print_preorder(n->left);
		print_preorder(n->right);
	}
}

// prints the data in a tree using a postorder traversal
void print_postorder(node *n)
{
	if (n != NULL)
	{
		print_postorder(n->left);
		print_postorder(n->right);
		cout << n->data << " ";
	}
}

// prints the data in a tree using an inorder traversal
void print_inorder(node *n)
{
	if (n != NULL)
	{
		print_inorder(n->left);
		cout << n->data << " ";
		print_inorder(n->right);
	}
}

// searches the tree for data. Returns 0 if data is not found, otherwise, returns the number of nodes visited
int search(int data)
{
	// no data
	if (root == NULL)
		return 0;

	node *n = root;
	int count = 0;
	while (n->data != data)
	{
		if (n->data > data)
		{
			if (n->left == NULL) return 0;
			count++;
			n = n->left;
		}
		else
		{
			if (n->right == NULL) return 0;
			count++;
			n = n->right;
		}
	}

	return n->data == data ? ++count : count;
}