#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// for flexibility purposes
const int NUM_OF_NODES = 100;

// the graph adjacency matrix
int graph[NUM_OF_NODES][NUM_OF_NODES];

// where I've been
bool visited[NUM_OF_NODES];

// the resulting tree.  Each node's parent is stored
int tree[NUM_OF_NODES];

// longest sequence calculated with stack
stack<int> sequence;
vector<int> seq;
int longest = 0;

void printnode(int nodelist)
{
	cout << nodelist << " ";
}

void printtree()
{
	cout << "\nThe resulting tree [Node, Parent]:\n";
	for (int i = 0; i < NUM_OF_NODES; i++)
		cout << "[" << (i) << ", " << tree[i] << "] ";
	cout << "\n";
}


// traverse each nodelist (row in the matrix)
void traverse(int nodelist)
{
	visited[nodelist] = true;   // been there done that
	printnode(nodelist);

	// find an unvisted node to select
	int i = 0;
	while (i < NUM_OF_NODES)
	{
		if (!visited[i] && graph[nodelist][i] == 1)
		{
			tree[i] = nodelist;
			sequence.push(i);
			traverse(i);         // "push" this node
			if (sequence.size() > longest)
			{
				longest = sequence.size();
				for (int i = 0; i < longest; i++)
				{
					seq.push_back(sequence.top());
					sequence.pop();
				}
				for (int i = seq.size() - 1; i >= 0; i--)
				{
					sequence.push(seq[i]);
				}
			}
			sequence.pop();
		}

		i++;
	}
}

// A function to fill a table from a text file
int fill_O_file()
{
	string buffer;

	// open source file
	ifstream fin("BiggieGraph.txt");
	if (!fin) { cerr << "Input file could not be opened\n"; exit(1); }

	// loop through strings in file & spit em' out
	int row = 0, col = 0;
	while (fin >> buffer) {
		// parse this row into the table
		for (int col = 0; col < NUM_OF_NODES; col++)
			graph[row][col] = buffer[col] - '0';
		row++;
	}

	// close file
	fin.close();
}


int main()
{
	cout << "The stack traversal path:\n";

	fill_O_file();

	for (int i = 0; i < NUM_OF_NODES; i++)
	{
		tree[i] = -1;
		visited[i] = false;
	}
		
	// "Push" 0
	sequence.push(0);
	traverse(0);
	cout << "\n";

	printtree();

	cout << "\nThe longest sequence has length " << longest << ".\nAnd the sequnce is: " << endl;
	for (int i = seq.size() - 1; i >= 0; i--)
		cout << seq[i] << " ";
	cout << "\n";
	
	return 0;
}