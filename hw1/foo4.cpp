/*
@author: Lawrence Wong
@version: 1/31/18
*/

#include <iostream>
#include <fstream>

using namespace std;

int foo4(int n)
{
	static int counter = 0;
	counter++;

	if (n > 0)
	{
		foo4(n - 1);
		foo4(n - 1);
	}

	return counter;
}

int main()
{
	ofstream fout("foo4.csv");

	fout << "n,return value" << "\n";
	for (int i = 0; i <= 16; i++)
	{
		fout << i << "," << foo4(i) << "\n";
	}
	fout << 32 << "," << foo4(32) << "\n";
	// fout << 64 << "," << foo4(64) << "\n";

	return 0;
}