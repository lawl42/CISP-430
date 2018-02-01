/*
@author: Lawrence Wong
@version: 1/31/18
*/

#include <iostream>
#include <fstream>

using namespace std;

int foo2(int n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			counter++;

	return counter;
}

int main()
{
	ofstream fout("foo2.csv");

	fout << "n,return value" << "\n";
	for (int i = 0; i <= 16; i++)
	{
		fout << i << "," << foo2(i) << "\n";
	}
	fout << 32 << "," << foo2(32) << "\n";
	fout << 64 << "," << foo2(64) << "\n";

	return 0;
}