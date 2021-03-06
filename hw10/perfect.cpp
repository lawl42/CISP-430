#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int lookup[26]; // default lookup is lowercase ascii value
struct wordstruct {
	string word;
	int count;
};
vector<wordstruct> words(28);

int main()
{
	// creating original lookup values
	for (int i = 0; i < 26; i++)
		lookup[i] = i + 97;

	// manipulations
	lookup['c' - 'a'] += 10;
	lookup['s' - 'a'] -= 1;
	lookup['r' - 'a'] += 3;
	lookup['t' - 'a'] += 2;
	lookup['f' - 'a'] -= 3;
	lookup['d' - 'a'] += 1;
	lookup['n' - 'a'] += 8;
	lookup['o' - 'a'] -= 1;
	lookup['u' - 'a'] += 5;
	lookup['k' - 'a'] += 6;

	// get words
	ifstream fin("keywords.txt");
	string buffer;
	while (fin >> buffer)
	{
		int hash = (lookup[buffer[0] - 'a'] + lookup[buffer[buffer.length() - 1] - 'a'] + buffer.length()) % 28;
		words[hash].word = buffer;
		words[hash].count++;
	}

	// output info
	cout << "Word\t\tCount\n";
	for (int i = 0; i < 28; i++)
		if (words[i].count > 0)
			cout << setw(10) << left << words[i].word << "\t" << words[i].count << "\n";

	// give user info requested
	l:
	while (true)
	{
		cout << "Please enter a word or \"done\" to exit: ";
		cin >> buffer;
		for (int i = 0; i < buffer.length(); i++)
		{
			if (!isalpha(buffer[i]) || isupper(buffer[i]))
			{
				cout << "\tINVALID WORD\n";
				goto l;
			}
		}
		if (buffer == "done") break;

		int hash = (lookup[buffer[0] - 'a'] + lookup[buffer[buffer.length() - 1] - 'a'] + buffer.length()) % 28;
		if (words[hash].word == buffer)
		{
			cout << "\t" << words[hash].count << "\n";
		}
		else
		{
			cout << "\tNOT FOUND\n";
		}
	}

	return 0;
}