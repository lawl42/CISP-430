#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

vector<int> lookup;
struct protein {
	string sequence;
	int count;
};
vector<protein> proteins(40);

int main()
{
	// establish lookup table
	for (int i = 0; i < 26; i++)
		lookup.push_back(i);

	ifstream fin ("proteins.txt");
	
	// read in proteins and hash them using linear rehashing
	string buffer;
	while (fin >> buffer)
	{
		int hash = (lookup[buffer[0] - 'A'] + (2 * lookup[buffer[1] - 'A'])) % 40;
		// linear rehashing
		while (proteins[hash].sequence != buffer && proteins[hash].count != 0)
			hash = ++hash % 40;
		proteins[hash].sequence = buffer;
		proteins[hash].count++;
	}

	// output info
	cout << "Protein\t\t\t\tCount\n";
	for (int i = 0; i < 40; i++)
		if (proteins[i].count > 0)
			cout << setw(30) << left << proteins[i].sequence << "\t" << proteins[i].count << "\n";

	// give user info requested
	l:
	while (true)
	{
		cout << "Please enter a sequence or \"DONE\" to exit: ";
		cin >> buffer;
		for (int i = 0; i < buffer.length(); i++)
		{
			if (!isalpha(buffer[i]) || islower(buffer[i]))
			{
				cout << "\tINVALID SEQUENCE\n";
				goto l;
			}
		}
		if (buffer == "DONE") break;

		int hash = (lookup[buffer[0] - 'A'] + (2 * lookup[buffer[1] - 'A'])) % 40;
		while (true)
		{
			if (proteins[hash].sequence == buffer)
			{
				cout << "\t" << proteins[hash].count << "\n";
				break;
			}
			hash = ++hash % 40;
			if (proteins[hash].count == 0)
			{
				cout << "\tNOT FOUND\n";
				break;
			}
		}
	}
	return 0;
}