#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string words[10] = { "auto", "break", "case", "const", "for", "switch", "struct", "while", "static", "continue" };
int lookup[26]; // default lookup is lowercase ascii value
int h[10]; // index = h(key) = (lookup[first_letter_of_key] + lookup[last_letter_of_key] + length_of_key) % 10

void print_table()
{
	for (int i = 0; i < 26; i++)
		cout << setw(3) << char(i + 97) << " ";
	cout << "\n";
	for (int i = 0; i < 26; i++)
		cout << setw(3) << lookup[i] << " ";
	cout << "\n";
}

void print_hash()
{
	for (int i = 0; i < 10; i++)
	{
		h[i] = (lookup[words[i][0] - 'a'] + lookup[words[i][words[i].length() - 1] - 'a'] + words[i].length()) % 10;
		cout << "Index: " << i << "\tKey: " << words[i] << "\tHash: " << h[i] << "\n";
	}
}
int main()
{
	// creating original lookup values
	for (int i = 0; i < 26; i++)
		lookup[i] = i + 97;
	
	// print original lookup table
	cout << "ORIGINAL LOOKUP TABLE\n";
	print_table();
	
	// print original hash values
	cout << "ORIGINAL HASH\n";
	print_hash();

	// manipulations
	cout << "\nAdd 3 to c, Add 3 to s, Add 4 to k\n";
	lookup['c' - 'a'] += 3;
	lookup['s' - 'a'] += 3;
	lookup['k' - 'a'] += 4;

	// print final lookup values
	cout << "\nFINAL LOOKUP TABLE\n";
	print_table();

	// print perfect hash
	cout << "PERFECT HASH\n";
	print_hash();

	return 0;
}