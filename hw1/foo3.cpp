/*
@author: Lawrence Wong
@version: 1/31/18
*/

#include <iostream>
#include <fstream>

using namespace std;

int foo3(int n)
{
	int counter = 0;
	for (int i = n; i > 0; i /= 2)
		counter++;

	return counter;
}

int main()
{
	ofstream fout("foo3.csv");

	fout << "n,return value" << "\n";
	for (int i = 0; i <= 16; i++)
	{
		fout << i << "," << foo3(i) << "\n";
	}
	fout << 32 << "," << foo3(32) << "\n";
	fout << 64 << "," << foo3(64) << "\n";

	return 0;
}
