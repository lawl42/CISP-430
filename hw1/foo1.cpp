/*
@author: Lawrence Wong
@version: 1/31/18
*/


#include <iostream>
#include <fstream>

using namespace std;

int foo1(int n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
		counter++;

	return counter;
}

int main()
{
	ofstream fout("foo1.csv");

	fout << "n,return value" << "\n";
	for (int i = 0; i <= 16; i++)
	{
		fout << i << "," << foo1(i) << "\n";
	}
	fout << 32 << "," << foo1(32) << "\n";
	fout << 64 << "," << foo1(64) << "\n";

	return 0;
}